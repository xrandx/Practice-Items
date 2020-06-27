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
	//��s1�д�ǰ������ ��w�� ��һ�γ��ֵĵط�
//����ҵ�, ���� ��w����ʼ��λ��, �� l ���ڵ�λ���±�
//����Ҳ���, ���� string::npos (string�ж���ľ�̬����)
	s1.rfind("lo");
	//��s1�дӺ���ǰ���� ��lo�� ��һ�γ��ֵĵط�
//����ҵ�, ���� ��lo����ʼ��λ��, �� l ���ڵ�λ���±�
//����Ҳ���, ���� string::npos
	s1.erase(5);// ȥ���±� 5 ��֮����ַ�
	s1.find("ll", 1)//���±�1��ʼ���� ��ll��
	s1 = "hello word";
	s1.replace(2,3, "haha");//��s1���±�2 ��ʼ��3���ַ����� ��haha��
//���: hehaha world

	s1 = "hello word";
	s1.replace(2,3, "haha", 1,2);
//��s1���±�2 ��ʼ��3���ַ�
//���� ��haha�� ���±�1��ʼ��2���ַ�
//���:heah world

	s1.insert(5, s2);// ��s2����s1�±�5��λ��
	s1.insert(2, s2, 5, 3);//��s2���±�5��ʼ��3���ַ�����s1�±�2��λ��
	printf("%s\n", s1.c_str());
// s1.c_str() ���ش�ͳ��const char * �����ַ���
//�Ҹ��ַ����� ��\0�� ��β
	int len = s1.length();
	char *p2 = new char[len + 1];
	s1.copy(p2, 5, 0);
	p2[5] = 0;
	cout << p2 << endl;
	// s1.copy(p2, 5, 0) ��s1���±�0���ַ���ʼ,
	//����һ���5���ַ����ȵ��ַ������������丳ֵ��p2
	//����ֵ����ʵ�ʸ����ַ����ĳ���

	s1.find_first_of("abcd");
//��s1�д�ǰ������ ��abcd�� ���κ�һ���ַ���һ�γ��ֵĵط�
//����ҵ�, �����ҵ���ĸ��λ��; ����Ҳ���, ���� string::npos
	s1.find_last_of("abcd");
//��s1�в��� ��abcd�� ���κ�һ���ַ����һ�γ��ֵĵط�
//����ҵ�, �����ҵ���ĸ��λ��; ����Ҳ���, ���� string::npos
	s1.find_first_not_of("abcd");
//��s1�д�ǰ�����Ҳ��� ��abcd�� �е���ĸ��һ�γ��ֵĵط�
//����ҵ�, �����ҵ���ĸ��λ��; ����Ҳ���, ���� string::npos
	s1.find_last_not_of("abcd");
//��s1�дӺ���ǰ���Ҳ��� ��abcd�� �е���ĸ��һ�γ��ֵĵط�
//����ҵ�, �����ҵ���ĸ��λ��; ����Ҳ���, ���� string::npos
	return 0;
}	
