//7-2 函数模板
#include <iostream> 
using namespace std;

template <class T>
void Swap(T & x, T & y)
{
	T tmp = x;
	x = y;
	y = tmp;
	cout << "swap T" << endl;
}

template <class T1, class T2>
//若不存在swap T1 T2， 当输入swap（int，double）时会产生二义性
void Swap(T1 & x, T2 & y)
{
	T2 tmp = (T2)x;
	x = y;
	y = tmp;
	cout << "swap T1 T2" << endl;
}

void Swap(int & x, int & y)
{
	int tmp = x;
	x = y;
	y = tmp;
	cout << "swap int" << endl;
}
int main()
{
	//先找参数完全匹配的普通函数(非由模板实例化而得的函数)
	//再找参数完全匹配的模板函数
	//再找实参经过自动类型转换后能够匹配的普通函数
	int a = 1, b = 2;
	double c = 1.1, d = 1.5;
	Swap(a, b);
	Swap(c, d);
	Swap(a, c);
	return 0;
}
