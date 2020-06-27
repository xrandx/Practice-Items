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
		//" typename "是一个C++程序设计语言中的关键字。 当用于泛型编程时是另一术语" class "的同义词。
		//这个关键字用于指出模板声明（或定义）中的非独立名称（dependent names）是类型名，而非变量名。
		for( it = lst.begin(); it != lst.end(); it++)
		{
			cout << *it << " ";
			//与其他顺序容器不同, list容器只能使用双向迭代器,
//因此不支持大于/小于比较运算符, []运算符和随机移动
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
	l1.remove(50);//删除和50相等的元素 
	Print(l1);
	l1.unique();//删除和前一个元素相等的元素 
	Print(l1);
	l1.merge(l2);//合并l2到l1，并清空l2   l2在l1之前 
	Print(l1);
	l1.reverse(); //反转链表 
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
	Print(l1);//把l2 	
	Print(l2);
	return 0;
}
