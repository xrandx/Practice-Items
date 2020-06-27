#include<iostream>
using namespace std;
class Complex
{
	public:
		double real, imag;
	public:
		Complex(double r1, double r2 = 0): real(r1), imag(r2)
		{
		}//这种方法直接给成员变量赋值
		Complex(int x): real(x)
		{
		}//重载
		//Complex(Complex c1);不允许这样构造 
		Complex(Complex c1, Complex c2);//声明
		Complex()
		{
			real = 0;
			imag = 0;
			cout << "no agrc" << endl;
		}
};

Complex::Complex(Complex c1, Complex c2)
{
	real = c1.real + c2.real;
	imag = c1.imag + c2.imag;
};

class Test
{
	public:
		Test(int n)
		{
		}//1
		Test(int n, int m)
		{
		}//2
		Test()
		{
		}//3
};

int main()
{
	Complex c(1,2), c1(1, 0);
	Complex no;
	cout << "no" << no.imag << no.real << endl;
	Complex *p = new Complex(1, 0);
	Complex i(1);
	Complex y(c1, c);
	cout << p->imag << i.real << y.imag;
	delete p;
	Test a[3] = {1, Test(1, 2)}; // 1 2 3
	Test a2[3] = {Test(2, 3), Test(1, 3), 1};// 2 2 1
	Test *pa[3] = {new Test(4), new Test(1, 2)};//指针数组 1 2 3
	return 0;
}
