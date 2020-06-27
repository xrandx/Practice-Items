/* 20161506146 汤鸿剑  */ 
/* Windows 10 / Dev C++ / VScode */

#include <stdio.h>
#include <stdlib.h>

const int maxn = 100;

typedef struct tag_queue
{
	int *data;
	int maxsize, rear, front;
} Queue, *Queueptr;

int IsEmpty(Queueptr q)
{
	if(q->front + 1 == q->rear)
	{
		printf("队列空。");
		return 1;
	}
	else
		return 0;
}

int IsFull(Queueptr q)
{
	if(q->rear == maxn - 1)
	{
		printf("队列满。");
		return 1;
	}
	else
		return 0;
}

void Enqueue(Queueptr q, int i)
{
	if(IsFull(q))
		return;
	else
	{
		q->data[++(q->rear)] = i;
	}
}

int Inqueue(Queueptr q)
{
	if(IsEmpty(q))
		return 0;
	else
		return q->data[++(q->front)];
}

void ViewQueue(Queueptr q)
{
	printf("front = %d\n", q->front);
	printf("rear = %d\n", q->rear);
	int i = q->front + 1;
	for(i; i<= q->rear; i++)
	{
		printf("%d >>> %d \n", i, q->data[i]);
	}
	return;
}

Queueptr qCreate(int maxsize)
{
	Queueptr q = (Queueptr)malloc(sizeof(Queue));
	q->data = (int *)malloc(maxsize * sizeof(int));
	q->front = 	q->rear = -1;
	q->maxsize = maxsize;
	return q;
}
 
int main()
{
	int i;
	Queueptr q = qCreate(maxn);
	scanf("%d", &i);
	Enqueue(q, i);
	scanf("%d", &i);
	Enqueue(q, i);
	scanf("%d", &i);
	Enqueue(q, i);
	scanf("%d", &i);
	Enqueue(q, i);
	scanf("%d", &i);
	Enqueue(q, i);
	ViewQueue(q);
}
