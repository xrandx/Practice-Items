#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;


template <class T>
void Print(T first, T last)
{
	for(; first != last; first++)
	{
		cout << *first << " "; //输出[first,last)
	}
	cout << endl;
}

class myless
{
	public:
		bool operator() (const int & c1, const int & c2)
		{
			return (c1 % 10) > (c2 % 10);
		}
};

int compare(const int a, const int b )
{
	return a < b;
}


int main()
{
	list<int> lst;
	for(int i = 1; i < 6; i++)
	{
		lst.push_back(i * 10 + 6 - i);
	}
	Print(lst.begin(), lst.end());
	//sort括号里只要返回true则认为a小于b   默认升序
	lst.sort(myless());//函数对象
	Print(lst.begin(), lst.end());
	lst.sort(compare);//普通函数
	Print(lst.begin(), lst.end());
	lst.sort(greater<int>());
	Print(lst.begin(), lst.end());
}
