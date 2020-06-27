#include <stdio.h>
#include <stdlib.h>

typedef struct tag_stackelem
{
	int num;
	tag_stackelem *next;
} stack, *stackptr;

void menu();
void LoopCLS();

stackptr InitStack(stackptr s)
{
	s = (stackptr)malloc(sizeof(stack));
	if(!s)
		printf("出错。");
	s->next = NULL;
	return s;
}

int DestroyStack(stackptr s)
{
	free(s);
	s = NULL;
	return 1;
}

int IsEmpty(stackptr s)
{
	//return(s->next? 0 : 1);
	return s->next == NULL;
}

int StackLength(stackptr s)
{
	int i = 0;
	stackptr p = s;

	if(IsEmpty(s))
	{
		printf("栈无元素。");
		return 0;
	}
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

int Push(stackptr s, int num)
{
	stackptr tmp;
	tmp = s->next;
	s->next = (stackptr)malloc(sizeof(stack));
	if(!s)
		return 0;
	s->next->num = num;
	s->next->next = tmp;
	return 1;
}

int Top(stackptr s)
{
	if(IsEmpty(s))
	{
		printf("栈无元素。");
		return 0;
	}
	return s->next->num;
}

int Pop(stackptr s)
{
	stackptr firstp;
	int i;
	if(IsEmpty(s))
	{
		printf("栈无元素。");
		return 0;
	}
	firstp = s->next;
	s->next = s->next->next;
	i = firstp->num;
	firstp->next = NULL;
	free(firstp);
	return i;
}

int ViewStack(stackptr s)
{
	if(IsEmpty(s))
	{
		printf("栈无元素。");
		return 0;
	}
	int i = 1;
	stackptr p = s->next;
	printf("0 --> Top\n");
	while(p)
	{
		printf("%d --> %d\n", i++, p->num);
		p = p->next;
	}
	return 1;
}

int main()
{
	stackptr s;
	int op;
	int i;
	if(s = InitStack(s))
		printf("初始化栈成功。\n");
	while(1)
	{
		menu();
		printf("\n%d\n", IsEmpty(s));
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				system("cls");
				printf("请输入元素：");
				scanf("%d", &i);
				if(Push(s, i))
					printf("Push成功。");
				break;
			case 2:
				system("cls");
				if(Pop(s))
					printf("Pop元素num为：%d",Pop(s));
				break;
			case 3:
				system("cls");
				if(Pop(s))
					printf("Top元素num为：%d",Top(s));
				break;
			case 4:
				system("cls");
				i = StackLength(s);
				if(i)
					printf("元素个数为：%d", i);
				break;
			case 5:
				system("cls");
				if(ViewStack(s))
					printf("完毕。");
				break;
			case 0:
				system("cls");
				DestroyStack(s);
				exit(1);
				break;
			default:
				system("cls");
				printf("输入失误。");
				break;
		}
		LoopCLS();
	}

	return 0;
}

void menu()
{
	printf("1.PUSH栈元素\n");
	printf("2.POP栈元素\n");
	printf("3.TOP栈元素\n");
	printf("4.查看元素个数\n");
	printf("5.浏览所有元素\n");

	printf("\n0.清空所用内存并退出\n");

}

void LoopCLS()
{
	getchar();
	printf("\n回车以返回菜单。\n");
	while(getchar()!='\n');
	system("cls");
	return;
}
