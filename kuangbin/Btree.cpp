/* 20161506146 汤鸿剑  */ 
/* Windows 10 / Dev C++ / VScode */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

const int maxn = 100;

typedef struct tag_btree
{
	int data;
	struct tag_btree* lchild;
	struct tag_btree* rchild;
} Btree, *Btreeptr, **Btreeptr2;

typedef struct tag_queue
{
	Btreeptr2 data;
	int maxsize, rear, front;
} Queue, *Queueptr;


Queueptr qCreate(int maxsize)
{
	Queueptr q = (Queueptr)malloc(sizeof(Queue));
	q->data = (Btreeptr *)malloc(maxsize * sizeof(Btreeptr));
	q->front = 	q->rear = -1;
	q->maxsize = maxsize;
	return q;
}

int IsEmpty(Queueptr q)
{
	if(q->front == q->rear)
	{
		return 1;
	}
	else
		return 0;
}

int IsFull(Queueptr q)
{
	if(q->rear == maxn - 1)
	{
		printf("队列满。\n");
		return 1;
	}
	else
		return 0;
}

void Enqueue(Queueptr q, Btreeptr i)
{
	if(IsFull(q))
		return;
	else
		q->data[++(q->rear)] = i;
}

Btreeptr Inqueue(Queueptr q)
{
	if(IsEmpty(q))
		return 0;
	else
		return q->data[++(q->front)];
}

Btreeptr bCreate()
{
	int n;
	Queueptr q = qCreate(maxn);
	Btreeptr BT, T;
	scanf("%d", &n);
	if(n == 0)
		return NULL;
	else
	{
		BT = (Btreeptr)malloc(sizeof(Btree));
		BT->data = n;
		BT->lchild = BT->rchild = NULL;
		Enqueue(q, BT);
	}
	while(!IsEmpty(q))
	{
		T = Inqueue(q);
		scanf("%d", &n);
		if(n == 0) T->lchild = NULL;
		else
		{
			T->lchild = (Btreeptr)malloc(sizeof(Btree));
			T->lchild->lchild = T->lchild->rchild = NULL;
			T->lchild->data = n;
			Enqueue(q, T->lchild);
		}
		scanf("%d", &n);
		if(n == 0) T->rchild = NULL;
		else
		{
			T->rchild = (Btreeptr)malloc(sizeof(Btree));
			T->rchild->lchild = T->rchild->rchild = NULL;
			T->rchild->data = n;
			Enqueue(q, T->rchild);
		}
	}
	return BT;
}

void PreorderTravelsal(Btreeptr t)
{
	if(t)
	{
		printf("%d  ", t->data);
		PreorderTravelsal(t->lchild);
		PreorderTravelsal(t->rchild);
	}
	return;
}

void InorderTravelsal(Btreeptr t)
{
	if(t)
	{
		InorderTravelsal(t->lchild);
		printf("%d  ", t->data);
		InorderTravelsal(t->rchild);
	}

	return;
}

void PostorderTravelsal(Btreeptr t)
{
	if(t)
	{
		PostorderTravelsal(t->lchild);
		PostorderTravelsal(t->rchild);
		printf("%d  ", t->data);
	}

	return;
}


/*先序非递归*/ 
void PreorderTravelsalNoRecursive(Btreeptr t)
{
	stack <Btreeptr> S;
	while(!S.empty() || t)
	{
		while(t)
		{
			printf("%d  ", t->data);
			S.push(t);
			t = t->lchild;
		}
		if(!S.empty())
		{
			t = S.top();
			S.pop();
			t = t->rchild;
		}
	}
	return;
}

/*中序非递归*/ 
void InorderTravelsalNoRecursive(Btreeptr t)
{
	stack <Btreeptr> S;
	while(!S.empty() || t)
	{
		while(t)
		{
			S.push(t);
			t = t->lchild;
		}
		if(!S.empty())
		{
			t = S.top();
			S.pop();
			printf("%d  ", t->data);
			t = t->rchild;
		}
	}
}

int main()
{
	printf("层序创建二叉树，输入0为空结点：\n");
	Btreeptr r = bCreate();
	printf("中序遍历\n");
	InorderTravelsal(r);
	printf("\n中序非递归遍历\n");
	InorderTravelsalNoRecursive(r);
	printf("\n后序遍历\n");
	PostorderTravelsal(r);
	printf("\n先序遍历\n");
	PreorderTravelsal(r);
	printf("\n先序非递归遍历\n");
	PreorderTravelsalNoRecursive(r);

	return 0;
}
