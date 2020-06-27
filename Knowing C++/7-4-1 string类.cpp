//string类
// string 类 是一个模板类, 它的定义如下:
// typedef basic_string<char> string;
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1("hello");//一个参数的构造函数
	string s2(8, '6');//两个参数的构造函数 int char？
	string month = "May";//赋值操作符初始化 
	//不提供以字符和整数为参数的构造函数
//错误的初始化方法：
/*	string error1 = 'c';
	string error2('c');
	string error3 = 1;
	string error(1);*/
	//char可以赋值给string对象 
	string s3;
	s3 = 'c';
	//构造的string太长而无法表达 ? 会抛出length_error异常

	//string 对象的长度用成员函数 length()读取；
	string s4("hhhhhh");
	cout << s4.length() << endl;
	//string 支持流读取运算符
	string s5;
	cin >> s5;
	//string 支持getline函数
	string s6;
	getline(cin, s6);
	//string的赋值和连接
	string s7("12345"), s8;
	s8 = s7;//用 ‘=’ 赋值
	s8.assign(s7);
	s8.assign(s7, 1, 3);//从s7中下标为1开始复制3个字符给s8
	cout << s8 << endl;
	s8[2] = '5';
	for(int i = 0; i < s8.length(); i++)
		cout << s8[i];
// 成员函数at会做范围检查, 如果超出范围, 会抛出
// out_of_range异常, 而下标运算符不做范围检查
	for(int i = 0; i < s8.length(); i++)
		cout << s8.at(i);
	//用 + 运算符连接字符串
	s7 += s8;
	//用成员函数 append 连接字符串
	string s9("good"), s10("morning!");
	s9.append(s10);
	cout << s9 << endl;
	s9.append(s10, 3, s10.size());
	cout << s9 << endl;//下标从3开始
	 //如果字符串内没有足够字符, 则复制到字符串最后一个字符
	string s11("hello"), s12("hello"), s13("hell");
	cout <<  bool(s11 == s12) << endl;
	cout <<  bool(s11 == s13)<< endl;
	cout <<  bool(s11 > s13)<< endl;
	
}



