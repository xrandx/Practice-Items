// ��Ա����ͷ����
#include <iostream>
class CTyre   //��̥��
{
	private:
		int radius; //�뾶
		int width; //���
	public:
		CTyre(int r, int w):radius(r), width(w) { }
};

class CEngine   //������
{
};

class CCar   //������ ? ������ࡱ
{
	private:
		int price; //�۸�
		CTyre tyre;
		CEngine engine;
// ��Ա����Ĺ��캯������˳��
// ? �ͳ�Ա���������е�˵��˳��һ��
// ? ���ڳ�Ա��ʼ���б��г��ֵ�˳���޹�
	public:
		CCar(int p, int tr, int tw);
};

CCar::CCar(int p, int tr, int w):price(p), tyre(tr, w)
{
};
// ��� CCar �಻���幹�캯��, ��
// CCar car; // error ? �������

int main()
{
// ��������������ʱ,
// ? S1: ִ�����г�Ա���� �Ĺ��캯��
// ? S2: ִ�� ����� �Ĺ��캯��
	CCar car(20000,17,225);
// �������Ķ�������ʱ,
// ? S1: ��ִ�� ����� ����������
// ? S2: ִ�� ��Ա���� ����������
// ��������˳��͹��캯���ĵ���˳���෴
	return 0;
}
