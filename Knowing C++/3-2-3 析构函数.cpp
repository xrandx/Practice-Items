#include<iostream>
using namespace std;

/*成员函数的一种
? 名字与类名相同
? 在前面加  ‘~’
? 没有参数和返回值
? 一个类最多只有一个析构函数*/

class test
{
	private:
		char *p;
	public:
		test()
		{
			p = new char[10];
			cout << "test构造函数" << endl;
		}
		~test()
		{
			delete []p;
			cout << "test析构函数" << endl;
		}
};


class test2
{
	private:
		int n;
	public:
		test2(int num = 1): n(num)
		{
			
		};
		~test2()
		{
			cout << "test2析构" << endl;
		}
};
/*
对象消亡时 -自动被调用
在对象消亡前做善后工作
    释放分配的空间等
定义类时没写析构函数, 则编译器生成缺省析构函数
    不涉及释放用户申请的内存释放等清理工作
定义了析构函数, 则编译器不生成缺省析构函数
*/
int main()
{
	test t1;//构造1次 
	test *p2 = new test[5];//构造5次 
	//1. delete 导致析构函数调用 
	delete []p2;//析构5次 
	cout << "析构5次 " << endl;
	test2 t2;
	cout << "对象数组生命期结束时" << endl; //先初始化的最后析构 
	//2. 对象数组生命期结束时 
	return 0;
} 



