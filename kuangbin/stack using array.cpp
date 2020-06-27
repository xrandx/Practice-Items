#include <stdio.h>
#include <stdlib.h>

typedef struct snode_tag
{
	int *arrptr;
	int top;
	int maxsize;
}*stackptr, stack;

stackptr Create(int maxsize)
{
	stackptr s = (stackptr)malloc(sizeof(stack));
	s->arrptr = (int *)malloc(maxsize * sizeof(int));
	s->top = -1;
	s->maxsize = maxsize;
	return s;
}

bool IsFull(stackptr s)
{
	return (s->top == s->maxsize-1);
}

bool Push(stackptr s, int i)
{
	if(IsFull(s))
	{
		printf("堆栈满。");
		return false;
	}
	else
	{
		s->arrptr[++(s->top)] = i;
		return true;
	}
}

bool IsEmpty(stackptr s)
{
	if(s->top == -1)
		return true;
	else
		return false;
}

int Pop(stackptr s)
{
	if(IsEmpty(s))
	{
		printf("堆栈空。");
		return 0;
	}

	else
	{
		return s->arrptr[(s->top)--];
	}
}

int main()
{
	int maxsize, i, n;
	stackptr s;
	printf("输入栈大小：");
	scanf("%d", &maxsize);
	s = Create(maxsize);
	if(s->top == -1)
		printf("初始化成功。\n");
	printf("1.Push元素\n");
	printf("2.Pop元素\n");
	printf("3.Top元素\n");


	while(1)
	{
		printf("\n选择：");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				printf("输入：");
				scanf("%d", &i);
				if(Push(s, i))
					printf("成功");
				else
					printf("失败");
				break;
			case 2:
				printf("元素为：%d", Pop(s));
				break;
			case 3:
				printf("Top元素为：%d", s->arrptr[s->top]);
				break;
		}
	}
	return 0;
}


