/* 20161506146 汤鸿剑  */ 
/* Windows 10 / Dev C++ / VScode */
/* 双向循环队列 */ 
#include <stdio.h>
#include <stdlib.h>

typedef struct tag_cirqueue
{
	int *arr;
	int front;
	int rear;
	int maxsize;
} cirqueue, *cirqueueptr;

cirqueueptr qCreate(int maxsize)
{
	cirqueueptr q = (cirqueueptr)malloc(sizeof(cirqueue));
	q->arr = (int *)malloc(maxsize * sizeof(int));
	q->maxsize = maxsize;
	q->front = q->rear = 0;
	return q;
}

bool IsFull(cirqueueptr q)
{
	return ((q->rear + 1) % q->maxsize == q->front);
}

bool IsEmpty(cirqueueptr q)
{
	return (q->front == q->rear);
}

bool Enqueue(int i, cirqueueptr q)
{
	if(IsFull(q))
	{
		printf("队列已满。");
		return false;
	}
	else
	{
		q->rear = (q->rear + 1) % q->maxsize;
		q->arr[q->rear] = i;
		return true;
	}
}

int Inqueue(cirqueueptr q)
{
	if(IsEmpty(q))
	{
		printf("队列为空。");
		return 0;
	}
	else
	{
		q->front = (q->front + 1) % q->maxsize;
		return q->arr[q->front];
	}
}

void ViewQueue(cirqueueptr q)
{
	int i = q->front;
	if(IsEmpty(q))
	{
		printf("队列为空。");
	}
	else
	{
		while(i != q->rear)
		{
			i = (i + 1) % q->maxsize;
			printf("%d --> %d\n", i, q->arr[i]);
		}
	}
}

void LoopCLS()
{
	getchar();
	printf("\n回车以返回菜单。\n");
	while (getchar() != '\n')
		;
	system("cls");
	return;
}

void menu()
{
	printf("1.入队\n");
	printf("2.出队\n");
	printf("3.显示队列\n");
}

int main()
{
	cirqueueptr q;
	int i;
	int n;
	int op = 0;
	printf("输入队列长度：");
	scanf("%d", &i);
	i++; 
	q = qCreate(i);
	while (1)
	{
		menu();
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				printf("输入数据：");
				scanf("%d", &n);
				Enqueue(n, q);
				break;
			case 2:
				if(n = Inqueue(q))
					printf("输出数据为：%d", n);
				break;
			case 3:
				ViewQueue(q);
				break;
		}
		LoopCLS();
	}
	return 0;
}
