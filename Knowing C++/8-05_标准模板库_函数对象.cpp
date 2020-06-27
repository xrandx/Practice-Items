#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

//Dev C++   Accumulate 源代码 
//template<typename _InputIterator, typename _Tp,
//         typename _BinaryOperation>
//_Tp accumulate(_InputIterator __first, _InputIterator __last,
//               _Tp __init, _BinaryOperation __binary_op)
//{
//	for ( ; __first != __last; ++__first)
//		__init = __binary_op(__init, *__first);
//	return __init;
//}


int sumsquares(const int & total, const int & value)
{
	return total + value * value;
}

template <class T>
void Print(T first, T last)
{
	for(; first != last; first++)
	{
		cout << *first << " "; //输出[first,last)
	}
	cout << endl;
}

template <class T> //每个声明一次
class sumpower
{
	private:
		int power;
	public:
		sumpower(int p):power(p) {};
		const T operator ()( const T & total, const T & value)
		{
			T v = value;
			for(int i = 0; i < power - 1; i++)
				v = v * value;
			return v + total;
		}
};

int main()
{
	vector<int> a;
	for(int i = 0; i < 10; i++)
		a.push_back(i+1);
	Print(a.begin(), a.end());
	cout << "2" << endl;
	cout << accumulate(a.begin(), a.end(),0, sumsquares) << endl;//实例化为
//	int accumulate(vector<int>::iterator first,vector<int>::iterator last,
//	               int init,int ( * op)( int,int))
//	{
//		for ( ; first != last; ++first)
//			init = op(init, *first);
//		return init;
//	}
	cout << "3" << endl;
	sumpower<int> p(3);
	cout << accumulate(a.begin(), a.end(), 0, p);
//	int accumulate(vector<int>::iterator first,vector<int>::iterator last,
//	               int init, SumPowers<int> op)
//	{
//		for ( ; first != last; ++first)
//			init = op(init, *first);
//		return init;
//	}
}
