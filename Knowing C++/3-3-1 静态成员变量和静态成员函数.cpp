#include<iostream>
using namespace std;

class rectangle
{
	private:
		double l, w;
		static int num; // 必须初始化?初始化错误
	public:
		rectangle(double length = 0, double width = 0)
		{
			num++;
			l = length;
			w = width;
			cout << "构造函数\n";
		}
		~rectangle()
		{
			cout << "rectangle析构" <<" 个数为: " << num << endl;
		}
		//在复制构造函数中也要++，因为在默认复制过程中不会++ 
		//却会销毁临时的复制对象进而--，所以在这里要加回来 
		rectangle(const rectangle& t)
		{
			num++;
		}
		//在静态成员函数中，不能访问非静态成员变量，
		//也不能调用非静态成员函数
		static void print()
		{
			cout << "hello" << endl;
		}
};

int rectangle::num = 0; //如此初始化
// 必须在定义类的文件中对静态成员变量进行一次说明
//或初始化。否则编译能通过，链接不能通过。

int main()
{
//静态成员变量相当于全局变量
	rectangle r1;
	rectangle r2(r1); 
	return 0;

}
