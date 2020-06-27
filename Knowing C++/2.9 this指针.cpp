#include<iostream>
using namespace std;
	//this指针相当于翻译c++到c
	//this作用于当前对象，就是指向成员函数所作用的对象
class Complex
{
	public:
		double real, imag;
		void Print()
		{
			cout << real << "," << imag << endl ;
		}
		Complex(double r,double i):real(r),imag(i) //复制构造做的构造函数
		{  }
		Complex addone()
		{
			this->real++;
			return *this;//记得
		}
//		相当于 
//		Complex addone(Complex* this)
//		{
//			this->real++;
//			return *this;//记得
//		}
};
class H
{
	int i;
	public:
		void hello()
		{
			cout << "hello" << endl;
			//cout << "hello"<< i << endl; //若指针为空则错误
			//相当于
			//void  hello(H *this)
			//cout << "hello"<< this->i << endl;
		}
};
int main()
{
	Complex c1(1,1), c2(0,0);
	c1.Print();
	c2.Print();
	c2 = c1.addone(); //addone把c1的real++然后把c1返回给c2
	c1.Print();
	c2.Print();
	H *p;
	p->hello();
	return 0;
}
