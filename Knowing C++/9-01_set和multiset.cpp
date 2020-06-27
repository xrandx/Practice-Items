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
