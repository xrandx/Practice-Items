### set��multiset

? �ڲ�Ԫ���������У���Ԫ�ز����λ��ȡ��������ֵ�������ٶȿ졣

? ���˸��������еĺ����⣬��֧�����³�Ա������

- find: ���ҵ���ĳ��ֵ ��Ԫ��(xС��y��yС��xͬʱ��������Ϊ���)
- lower_bound : ����ĳ���½�
- upper_bound : ����ĳ���Ͻ�
- equal_range : ͬʱ�����Ͻ���½�
- count :�������ĳ��ֵ��Ԫ�ظ���(xС��y��yС��xͬʱ��������Ϊ���)
- insert: ���Բ���һ��Ԫ�ػ�һ������


<br>

### multiset
```CPP
template<class Key, class Pred = less<Key>,
class A = allocator<Key> >
class multiset { ���� };
```
- Pred���͵ı���������multiset �е�Ԫ�أ���һ������һ��С������ô����ġ�multiset���й����У��Ƚ�����Ԫ��x,y�Ĵ�С����������������һ�� Pred���͵ı������ٶ�Ϊ op,�����ʽop(x,y) ����ֵΪtrue,�� x��yС��
Pred��ȱʡ������ less<Key>��

- less ģ��Ķ��壺
```CPP
template<class T>
struct less : public binary_function<T, T, bool>
{ bool operator()(const T& x, const T& y) { return x < y ; } const; };
//lessģ���ǿ� < ���Ƚϴ�С��
```
<br>

### multiset �ĳ�Ա����
```CPP 
iterator find(const T & val);
// �������в���ֵΪval��Ԫ�أ������������������Ҳ���������end()��

iterator insert(const T & val);
// ��val���뵽�����в��������������

void insert( iterator first,iterator last); 
// ������[first,last)����������

int count(const T & val);
//  ͳ���ж��ٸ�Ԫ�ص�ֵ��val��ȡ�

iterator lower_bound(const T & val);
// ����һ������λ�� it,ʹ��[begin(),it) �����е�Ԫ�ض��� val С��

iterator upper_bound(const T & val);
// ����һ����С��λ�� it,ʹ��[it,end()) �����е�Ԫ�ض��� val ��

pair<iterator,iterator> equal_range(const T & val);
// ͬʱ���lower_bound��upper_bound��

iterator erase(iterator it);
//ɾ��itָ���Ԫ�أ�����������Ԫ�صĵ�����(Visual studio 2010����ˣ�������C++��׼��Dev C++�У�����ֵ��������)��
```

### multiset ���÷�
```CPP
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

template<class T>
void Print(T first, T last)
{
	for(; first != last; first++)
		cout << *first << " ";
	cout << endl;
}

class A
{
	private:
		int n;
	public:
		A(int n_) {	n = n_;	};
		friend bool operator < (const A & a1, const A & a2)
		{
			return a1.n < a2.n;
		}
		friend ostream & operator << (ostream & o, const A & a2)
		{
			o << a2.n;
			return o;
		}
		friend class MyLess;
};

struct MyLess
{
	bool operator()( const A & a1, const A & a2)
	{
		return ( a1.n % 10 ) < (a2.n % 10);//����λ���Ƚϴ�С 
	}
};

int main()
{
	int a[6] = { 4,22,19,8,33,40};
	multiset<A> m1;
	m1.insert(a, a + 6);
	Print(m1.begin(), m1.end());
	m1.insert(22);
	Print(m1.begin(), m1.end());
	cout <<"count:" << m1.count(22) << endl;
	multiset<A>::iterator pp = m1.find(50);
	cout << *pp << endl; //�Ҳ�������end() 
	cout << "end():" <<*m1.end() << endl;
	cout<< "1):"  << *m1.lower_bound(22) << endl;//����it [begin(), it) ��������ֵ��22С 
	cout<< "2):"  << *m1.lower_bound(3) << endl;//�����ڷ���begin()
	cout<< "3):"  << *m1.upper_bound() << endl;//����it  [it, end()) ��������ֵ��8�� 
	cout<< "4):"  << *m1.upper_bound(50) << endl;//�����ڷ���end() 
	//pp = m1.erase(m1.lower_bound(22));//dev-cpp�������� 
//	ɾ��itָ���Ԫ�أ�����������Ԫ�صĵ�����(Visual studio 2010����ˣ�������
//	C++��׼��Dev C++�У�����ֵ��������)��
	m1.erase(m1.lower_bound(22),m1.upper_bound(22));
	Print(m1.begin(), m1.end());
	return 0;
}
```
<br>

### set
```cpp
template<class Key, class Pred = less<Key>,
class A = allocator<Key> >
class set { �� }
//����set�����е�Ԫ��ʱ�����Բ��롣
```
```CPP
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	typedef set<int>::iterator IT;
	int a[5] = { 3,4,6,1,2 };
	set<int> st(a,a+5); // st��1 2 3 4 6
	pair< IT,bool> result;
	result = st.insert(5); // st��� 1 2 3 4 5 6
	if( result.second) //����ɹ������������Ԫ��
		cout << *result.first << " inserted" << endl;
	else
		cout << * result.first << " already exists" << endl;
	pair<IT, IT>bounds = st.equal_range(4);
	cout << * bounds.first << "," << * bounds.second ; // 4,5
	return 0;
}
```
