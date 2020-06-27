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
		printf("��ջ����");
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
		printf("��ջ�ա�");
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
	printf("����ջ��С��");
	scanf("%d", &maxsize);
	s = Create(maxsize);
	if(s->top == -1)
		printf("��ʼ���ɹ���\n");
	printf("1.PushԪ��\n");
	printf("2.PopԪ��\n");
	printf("3.TopԪ��\n");


	while(1)
	{
		printf("\nѡ��");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				printf("���룺");
				scanf("%d", &i);
				if(Push(s, i))
					printf("�ɹ�");
				else
					printf("ʧ��");
				break;
			case 2:
				printf("Ԫ��Ϊ��%d", Pop(s));
				break;
			case 3:
				printf("TopԪ��Ϊ��%d", s->arrptr[s->top]);
				break;
		}
	}
	return 0;
}


