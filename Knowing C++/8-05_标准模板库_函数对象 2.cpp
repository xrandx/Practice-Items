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
		cout << *first << " "; //���[first,last)
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
	//sort������ֻҪ����true����ΪaС��b   Ĭ������
	lst.sort(myless());//��������
	Print(lst.begin(), lst.end());
	lst.sort(compare);//��ͨ����
	Print(lst.begin(), lst.end());
	lst.sort(greater<int>());
	Print(lst.begin(), lst.end());
}
