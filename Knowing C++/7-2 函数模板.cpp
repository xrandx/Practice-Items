//7-2 ����ģ��
#include <iostream> 
using namespace std;

template <class T>
void Swap(T & x, T & y)
{
	T tmp = x;
	x = y;
	y = tmp;
	cout << "swap T" << endl;
}

template <class T1, class T2>
//��������swap T1 T2�� ������swap��int��double��ʱ�����������
void Swap(T1 & x, T2 & y)
{
	T2 tmp = (T2)x;
	x = y;
	y = tmp;
	cout << "swap T1 T2" << endl;
}

void Swap(int & x, int & y)
{
	int tmp = x;
	x = y;
	y = tmp;
	cout << "swap int" << endl;
}
int main()
{
	//���Ҳ�����ȫƥ�����ͨ����(����ģ��ʵ�������õĺ���)
	//���Ҳ�����ȫƥ���ģ�庯��
	//����ʵ�ξ����Զ�����ת�����ܹ�ƥ�����ͨ����
	int a = 1, b = 2;
	double c = 1.1, d = 1.5;
	Swap(a, b);
	Swap(c, d);
	Swap(a, c);
	return 0;
}
