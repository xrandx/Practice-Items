#include<iostream>
using namespace std;

class rectangle
{
	private:
		double l, w;
		static int num; // �����ʼ��?��ʼ������
	public:
		rectangle(double length = 0, double width = 0)
		{
			num++;
			l = length;
			w = width;
			cout << "���캯��\n";
		}
		~rectangle()
		{
			cout << "rectangle����" <<" ����Ϊ: " << num << endl;
		}
		//�ڸ��ƹ��캯����ҲҪ++����Ϊ��Ĭ�ϸ��ƹ����в���++ 
		//ȴ��������ʱ�ĸ��ƶ������--������������Ҫ�ӻ��� 
		rectangle(const rectangle& t)
		{
			num++;
		}
		//�ھ�̬��Ա�����У����ܷ��ʷǾ�̬��Ա������
		//Ҳ���ܵ��÷Ǿ�̬��Ա����
		static void print()
		{
			cout << "hello" << endl;
		}
};

int rectangle::num = 0; //��˳�ʼ��
// �����ڶ�������ļ��жԾ�̬��Ա��������һ��˵��
//���ʼ�������������ͨ�������Ӳ���ͨ����

int main()
{
//��̬��Ա�����൱��ȫ�ֱ���
	rectangle r1;
	rectangle r2(r1); 
	return 0;

}
