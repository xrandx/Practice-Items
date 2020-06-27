#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("hello"), s2("hello"), s3("hell");
	int f1 = s1.compare(s2);
	int f2 = s1.compare(s3);
	int f3 = s3.compare(s1);
	int f4 = s1.compare(1, 2, s3, 0, 3); //s1 1-2; s3 0-3
	int f5 = s1.compare(0, s1.size(), s3); //s1 0-end
	cout << f1 << endl << f2 << endl << f3 << endl;
	cout << f4 << endl << f5 << endl;
//0 // hello == hello
//1 // hello > hell
//-1 // hell < hello
//-1 // el < hell
//1 // hello > hell
	s1 = "helloworld";
	s2 = s1.substr(4, 5);
	cout << s2 << endl;
	swap(s1, s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << (int)s1.find("w");
	//在s1中从前向后查找 “w” 第一次出现的地方
//如果找到, 返回 “w”开始的位置, 即 l 所在的位置下标
//如果找不到, 返回 string::npos (string中定义的静态常量)
	s1.rfind("lo");
	//在s1中从后向前查找 “lo” 第一次出现的地方
//如果找到, 返回 “lo”开始的位置, 即 l 所在的位置下标
//如果找不到, 返回 string::npos
	s1.erase(5);// 去掉下标 5 及之后的字符
	s1.find("ll", 1)//从下标1开始查找 “ll”
	s1 = "hello word";
	s1.replace(2,3, "haha");//将s1中下标2 开始的3个字符换成 “haha”
//输出: hehaha world

	s1 = "hello word";
	s1.replace(2,3, "haha", 1,2);
//将s1中下标2 开始的3个字符
//换成 “haha” 中下标1开始的2个字符
//输出:heah world

	s1.insert(5, s2);// 将s2插入s1下标5的位置
	s1.insert(2, s2, 5, 3);//将s2中下标5开始的3个字符插入s1下标2的位置
	printf("%s\n", s1.c_str());
// s1.c_str() 返回传统的const char * 类型字符串
//且该字符串以 ‘\0’ 结尾
	int len = s1.length();
	char *p2 = new char[len + 1];
	s1.copy(p2, 5, 0);
	p2[5] = 0;
	cout << p2 << endl;
	// s1.copy(p2, 5, 0) 从s1的下标0的字符开始,
	//制作一个最长5个字符长度的字符串副本并将其赋值给p2
	//返回值表明实际复制字符串的长度

	s1.find_first_of("abcd");
//在s1中从前向后查找 “abcd” 中任何一个字符第一次出现的地方
//如果找到, 返回找到字母的位置; 如果找不到, 返回 string::npos
	s1.find_last_of("abcd");
//在s1中查找 “abcd” 中任何一个字符最后一次出现的地方
//如果找到, 返回找到字母的位置; 如果找不到, 返回 string::npos
	s1.find_first_not_of("abcd");
//在s1中从前向后查找不在 “abcd” 中的字母第一次出现的地方
//如果找到, 返回找到字母的位置; 如果找不到, 返回 string::npos
	s1.find_last_not_of("abcd");
//在s1中从后向前查找不在 “abcd” 中的字母第一次出现的地方
//如果找到, 返回找到字母的位置; 如果找不到, 返回 string::npos
	return 0;
}	
