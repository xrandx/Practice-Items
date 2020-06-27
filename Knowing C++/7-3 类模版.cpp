#include <iostream>
using namespace std;

template <class T1, class T2>
class Pair{
    public:
    T1 key;
    T2 value;
    Pair(T1 k, T2 v): key(k), value(v){};
    bool operator < (const Pair<T1, T2> & p)const;
};
template <class T1, class T2>
bool Pair<T1, T2>::operator < (const Pair<T1, T2> & p) const{
    return key < p.key;
}

int main()
{
    Pair<string, int> student("Tom", 19);
// ����������ģ��������Ĺ��̽���ģ���ʵ����
// -�������Զ��þ������������
// -�滻��ģ���е����Ͳ���, ����ģ����Ĵ���
// ����ģ��ʵ�����õ������ģ����
// -Ϊ���Ͳ���ָ�����������Ͳ�ͬ, �õ���ģ���಻ͬ
	Pair<string, double> score("Tim", 98.5);
    cout << student.key << " "<< student.value << endl;
    
    return 0;
}
//�и����������ϵ�Ͳ���ϸ�˽���
// ��ģ����̳�
// ��ģ����������ģ��
// ģ���� (����ģ��������/�����Ͳ���ʵ���������)
// ��������ģ��
// ��ͨ����������ģ��
// ģ������������ͨ��