#include<iostream>
using namespace std;

class Complex
{
	public:
		double real, imag;
	public:
		Complex(double r1 = 0, double r2 = 0): real(r1), imag(r2){
			cout << "初始化" << endl;
		}//这种方法直接给成员变量赋值  有默认参数所以无法同时和 Complex()并存 
		//不允许 Complex(Complex c)
		/*Complex()
		{
			real = 0;	
			imag = 0;
		cout << "Complex() was called." << endl;
		}*/
		Complex(const Complex &c)//复制构造函数 
		{
			cout << "复制构造函数 " << endl;
		}
		Complex(int x)
		{
			real = x;
			imag = 0;
			cout << "类型转换构造函数" << endl;
		} 
};
void fun1(Complex a) 
{
	cout << "fun1() was called." << endl;
}

Complex fun2() 
{
	Complex a(1, 1);
	cout << "fun2() was called." << endl;
	return a;
}

int main()
{
	//1 初始化 
	Complex c1;//默认无参构造 
	Complex c2(c1);//初始化语句
	//Complex c2 = c1; //与以上等价 初始化语句而不是赋值语句
	c2 = c1;//赋值语句 
	//2 函数调用时 
	fun1(c2);//a先调用复制构造函数 
	//3 函数返回时
	cout << fun2().imag << " was called." << endl;
	//然而在devcpp中没有被调用 是gcc做了优化，返回值为对象时，不再产生临时对象，因而不再调用复制构造函数。
	//http://blog.csdn.net/sxhelijian/article/details/50977946
	//copy elision 拷贝省略,在这里也叫具名返回值优化（named return value optimization）
	//类型转换构造函数：不是复制构造，只有一个参数 
	Complex c3 = 6; //不建立临时对象 
	c1 = 5;//建立临时对象 5被转换为对象再赋值 
	cout << c1.real << endl;
	
} 
