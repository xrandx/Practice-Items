//string��
// string �� ��һ��ģ����, ���Ķ�������:
// typedef basic_string<char> string;
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1("hello");//һ�������Ĺ��캯��
	string s2(8, '6');//���������Ĺ��캯�� int char��
	string month = "May";//��ֵ��������ʼ�� 
	//���ṩ���ַ�������Ϊ�����Ĺ��캯��
//����ĳ�ʼ��������
/*	string error1 = 'c';
	string error2('c');
	string error3 = 1;
	string error(1);*/
	//char���Ը�ֵ��string���� 
	string s3;
	s3 = 'c';
	//�����string̫�����޷���� ? ���׳�length_error�쳣

	//string ����ĳ����ó�Ա���� length()��ȡ��
	string s4("hhhhhh");
	cout << s4.length() << endl;
	//string ֧������ȡ�����
	string s5;
	cin >> s5;
	//string ֧��getline����
	string s6;
	getline(cin, s6);
	//string�ĸ�ֵ������
	string s7("12345"), s8;
	s8 = s7;//�� ��=�� ��ֵ
	s8.assign(s7);
	s8.assign(s7, 1, 3);//��s7���±�Ϊ1��ʼ����3���ַ���s8
	cout << s8 << endl;
	s8[2] = '5';
	for(int i = 0; i < s8.length(); i++)
		cout << s8[i];
// ��Ա����at������Χ���, ���������Χ, ���׳�
// out_of_range�쳣, ���±������������Χ���
	for(int i = 0; i < s8.length(); i++)
		cout << s8.at(i);
	//�� + ����������ַ���
	s7 += s8;
	//�ó�Ա���� append �����ַ���
	string s9("good"), s10("morning!");
	s9.append(s10);
	cout << s9 << endl;
	s9.append(s10, 3, s10.size());
	cout << s9 << endl;//�±��3��ʼ
	 //����ַ�����û���㹻�ַ�, ���Ƶ��ַ������һ���ַ�
	string s11("hello"), s12("hello"), s13("hell");
	cout <<  bool(s11 == s12) << endl;
	cout <<  bool(s11 == s13)<< endl;
	cout <<  bool(s11 > s13)<< endl;
	
}



