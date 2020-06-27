### set和multiset

? 内部元素有序排列，新元素插入的位置取决于它的值，查找速度快。

? 除了各容器都有的函数外，还支持以下成员函数：

- find: 查找等于某个值 的元素(x小于y和y小于x同时不成立即为相等)
- lower_bound : 查找某个下界
- upper_bound : 查找某个上界
- equal_range : 同时查找上界和下界
- count :计算等于某个值的元素个数(x小于y和y小于x同时不成立即为相等)
- insert: 用以插入一个元素或一个区间


<br>

### multiset
```CPP
template<class Key, class Pred = less<Key>,
class A = allocator<Key> >
class multiset { …… };
```
- Pred类型的变量决定了multiset 中的元素，“一个比另一个小”是怎么定义的。multiset运行过程中，比较两个元素x,y的大小的做法，就是生成一个 Pred类型的变量，假定为 op,若表达式op(x,y) 返回值为true,则 x比y小。
Pred的缺省类型是 less<Key>。

- less 模板的定义：
```CPP
template<class T>
struct less : public binary_function<T, T, bool>
{ bool operator()(const T& x, const T& y) { return x < y ; } const; };
//less模板是靠 < 来比较大小的
```
<br>

### multiset 的成员函数
```CPP 
iterator find(const T & val);
// 在容器中查找值为val的元素，返回其迭代器。如果找不到，返回end()。

iterator insert(const T & val);
// 将val插入到容器中并返回其迭代器。

void insert( iterator first,iterator last); 
// 将区间[first,last)插入容器。

int count(const T & val);
//  统计有多少个元素的值和val相等。

iterator lower_bound(const T & val);
// 查找一个最大的位置 it,使得[begin(),it) 中所有的元素都比 val 小。

iterator upper_bound(const T & val);
// 查找一个最小的位置 it,使得[it,end()) 中所有的元素都比 val 大。

pair<iterator,iterator> equal_range(const T & val);
// 同时求得lower_bound和upper_bound。

iterator erase(iterator it);
//删除it指向的元素，返回其后面的元素的迭代器(Visual studio 2010上如此，但是在C++标准和Dev C++中，返回值不是这样)。
```

### multiset 的用法
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
		return ( a1.n % 10 ) < (a2.n % 10);//按个位数比较大小 
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
	cout << *pp << endl; //找不到返回end() 
	cout << "end():" <<*m1.end() << endl;
	cout<< "1):"  << *m1.lower_bound(22) << endl;//返回it [begin(), it) 区间所有值比22小 
	cout<< "2):"  << *m1.lower_bound(3) << endl;//不存在返回begin()
	cout<< "3):"  << *m1.upper_bound() << endl;//返回it  [it, end()) 区间所有值比8大 
	cout<< "4):"  << *m1.upper_bound(50) << endl;//不存在返回end() 
	//pp = m1.erase(m1.lower_bound(22));//dev-cpp上有问题 
//	删除it指向的元素，返回其后面的元素的迭代器(Visual studio 2010上如此，但是在
//	C++标准和Dev C++中，返回值不是这样)。
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
class set { … }
//插入set中已有的元素时，忽略插入。
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
	set<int> st(a,a+5); // st是1 2 3 4 6
	pair< IT,bool> result;
	result = st.insert(5); // st变成 1 2 3 4 5 6
	if( result.second) //插入成功则输出被插入元素
		cout << *result.first << " inserted" << endl;
	else
		cout << * result.first << " already exists" << endl;
	pair<IT, IT>bounds = st.equal_range(4);
	cout << * bounds.first << "," << * bounds.second ; // 4,5
	return 0;
}
```
