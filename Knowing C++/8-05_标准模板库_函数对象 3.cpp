#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
using namespace std;


class MyLess
{
	public:
		bool operator() (const int & a1, const int & a2)
		{
			if( ( a1 % 10 ) < (a2 % 10) )//个位数大的为大（在最右） 
				return true;
			else
				return false;
		}
};

bool MyCompare(int a1,int a2)
{
	if( ( a1 % 10 ) < (a2 % 10) )
		return false;
	else
		return true;//个位数小的为大（在最右） 
}

template <class T, class Pred>
T MyMax(T first, T last, Pred myless)
{
	T tmpMax = first;
	for(; first != last; first++)
	{
		if(myless(*tmpMax, *first))
			tmpMax = first;
	}
	return tmpMax;
}
//input iterator 
//predicate
int main()
{
	int a[] = {35,7,13,19,12};
	cout << * MyMax(a, a+5, MyLess()) << endl;
	cout << * MyMax(a, a+5, MyCompare) << endl;
	return 0;
}


