#include<iostream>
using namespace std;
	//thisָ���൱�ڷ���c++��c
	//this�����ڵ�ǰ���󣬾���ָ���Ա���������õĶ���
class Complex
{
	public:
		double real, imag;
		void Print()
		{
			cout << real << "," << imag << endl ;
		}
		Complex(double r,double i):real(r),imag(i) //���ƹ������Ĺ��캯��
		{  }
		Complex addone()
		{
			this->real++;
			return *this;//�ǵ�
		}
//		�൱�� 
//		Complex addone(Complex* this)
//		{
//			this->real++;
//			return *this;//�ǵ�
//		}
};
class H
{
	int i;
	public:
		void hello()
		{
			cout << "hello" << endl;
			//cout << "hello"<< i << endl; //��ָ��Ϊ�������
			//�൱��
			//void  hello(H *this)
			//cout << "hello"<< this->i << endl;
		}
};
int main()
{
	Complex c1(1,1), c2(0,0);
	c1.Print();
	c2.Print();
	c2 = c1.addone(); //addone��c1��real++Ȼ���c1���ظ�c2
	c1.Print();
	c2.Print();
	H *p;
	p->hello();
	return 0;
}
