#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


template <class T>
void Print(const list<T> & lst)
{
	int tmp = lst.size();
	if(tmp > 0)
	{
		typename list<T>::const_iterator it;
		//" typename "��һ��C++������������еĹؼ��֡� �����ڷ��ͱ��ʱ����һ����" class "��ͬ��ʡ�
		//����ؼ�������ָ��ģ�����������壩�еķǶ������ƣ�dependent names���������������Ǳ�������
		for( it = lst.begin(); it != lst.end(); it++)
		{
			cout << *it << " ";
			//������˳��������ͬ, list����ֻ��ʹ��˫�������,
//��˲�֧�ִ���/С�ڱȽ������, []�����������ƶ�
		}
		cout << endl;
	}
}
int main()
{
	list<int> l1;
	for(int i = 1; i < 6; i++)
	{
		l1.push_back(i * 10);
	}
	list<int> l2;
	for(int i = 1; i < 6; i++)
	{
		l2.push_front(i);
	}
	Print(l1);
	Print(l2);
	l2.sort();
	Print(l2);
	l2.pop_back(); l2.pop_front();
	Print(l2);
	l1.push_back(10);l1.push_back(10);
	Print(l1);
	l1.remove(50);//ɾ����50��ȵ�Ԫ�� 
	Print(l1);
	l1.unique();//ɾ����ǰһ��Ԫ����ȵ�Ԫ�� 
	Print(l1);
	l1.merge(l2);//�ϲ�l2��l1�������l2   l2��l1֮ǰ 
	Print(l1);
	l1.reverse(); //��ת���� 
	Print(l1);
	for(int i = 1; i <= 4; i++)
	{
		l2.push_back(100 * i); 
	}
	Print(l2);
	list<int>::iterator p1, p2, p3;
	p1 = find(l1.begin(), l1.end(), 3);
	p2 = find(l2.begin(), l2.end(), 200);
	p3 = find(l2.begin(), l2.end(), 400);
	cout << *p1 << " "<< *p2 << " "<< *p3 << endl; 
	l1.splice(p1, l2, p2, p3);
	Print(l1);//��l2 	
	Print(l2);
	return 0;
}
