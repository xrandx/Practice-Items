#include<iostream>
using namespace std;

class Complex
{
	public:
		double real, imag;
	public:
		Complex(double r1 = 0, double r2 = 0): real(r1), imag(r2){
			cout << "��ʼ��" << endl;
		}//���ַ���ֱ�Ӹ���Ա������ֵ  ��Ĭ�ϲ��������޷�ͬʱ�� Complex()���� 
		//������ Complex(Complex c)
		/*Complex()
		{
			real = 0;	
			imag = 0;
		cout << "Complex() was called." << endl;
		}*/
		Complex(const Complex &c)//���ƹ��캯�� 
		{
			cout << "���ƹ��캯�� " << endl;
		}
		Complex(int x)
		{
			real = x;
			imag = 0;
			cout << "����ת�����캯��" << endl;
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
	//1 ��ʼ�� 
	Complex c1;//Ĭ���޲ι��� 
	Complex c2(c1);//��ʼ�����
	//Complex c2 = c1; //�����ϵȼ� ��ʼ���������Ǹ�ֵ���
	c2 = c1;//��ֵ��� 
	//2 ��������ʱ 
	fun1(c2);//a�ȵ��ø��ƹ��캯�� 
	//3 ��������ʱ
	cout << fun2().imag << " was called." << endl;
	//Ȼ����devcpp��û�б����� ��gcc�����Ż�������ֵΪ����ʱ�����ٲ�����ʱ����������ٵ��ø��ƹ��캯����
	//http://blog.csdn.net/sxhelijian/article/details/50977946
	//copy elision ����ʡ��,������Ҳ�о�������ֵ�Ż���named return value optimization��
	//����ת�����캯�������Ǹ��ƹ��죬ֻ��һ������ 
	Complex c3 = 6; //��������ʱ���� 
	c1 = 5;//������ʱ���� 5��ת��Ϊ�����ٸ�ֵ 
	cout << c1.real << endl;
	
} 
