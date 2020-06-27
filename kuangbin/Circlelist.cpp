/* 20161506146 ���轣  */ 
/* Windows 10 / Dev C++ / VScode */

#include <stdio.h>
#include <stdlib.h>

typedef struct tag_node
{
	struct tag_node *pre;
	struct tag_node *next;
	int num;
} node, *nodelnk;

void CreateList(nodelnk &head, nodelnk &tail, int n)
{
	nodelnk p;
	while(1)
	{
		if(!head)
		{
			p = (nodelnk)malloc(sizeof(node));
			tail = p;
			head = p;
			p->next = NULL;
			p->pre = NULL;
		}
		else
		{
			p = (nodelnk)malloc(sizeof(node));
			tail->next = p;
			p->next = NULL;
			p->pre = tail;
			tail = p;
		}
		printf("����һ����㣺");
		scanf("%d", &tail->num);
		if(n == 1)
		{
			head->pre = tail;
			tail->next = head;
			break;
		}
		n--;
	}
	return;

}

void ViewList(nodelnk head, nodelnk tail)
{
	nodelnk p;
	int i = 1;
	printf("��ͷ��β:\n");
	p = head;
	while(1)
	{
		printf("%d --> %d\n", i++, p->num);
		if(p->next == head)
			break;
		p = p->next;
	}
	printf("��β��ͷ:\n");
	p = tail;
	i = 1;
	while(1)
	{
		printf("%d --> %d\n", i++, p->num);
		if(p->pre == tail)
			break;
		p = p->pre;
	}
}

int main()
{
	nodelnk h, t;
	h = NULL;
	t = NULL;
	int i;
	printf("�����½������:");
	scanf("%d", &i);
	CreateList(h, t, i);
	ViewList(h, t);
	system("pause");
	return 0;
}
