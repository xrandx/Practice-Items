#include<iostream>
using namespace std;

/*��Ա������һ��
? ������������ͬ
? ��ǰ���  ��~��
? û�в����ͷ���ֵ
? һ�������ֻ��һ����������*/

class test
{
	private:
		char *p;
	public:
		test()
		{
			p = new char[10];
			cout << "test���캯��" << endl;
		}
		~test()
		{
			delete []p;
			cout << "test��������" << endl;
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
			cout << "test2����" << endl;
		}
};
/*
��������ʱ -�Զ�������
�ڶ�������ǰ���ƺ���
    �ͷŷ���Ŀռ��
������ʱûд��������, �����������ȱʡ��������
    ���漰�ͷ��û�������ڴ��ͷŵ�������
��������������, �������������ȱʡ��������
*/
int main()
{
	test t1;//����1�� 
	test *p2 = new test[5];//����5�� 
	//1. delete ���������������� 
	delete []p2;//����5�� 
	cout << "����5�� " << endl;
	test2 t2;
	cout << "�������������ڽ���ʱ" << endl; //�ȳ�ʼ����������� 
	//2. �������������ڽ���ʱ 
	return 0;
} 



