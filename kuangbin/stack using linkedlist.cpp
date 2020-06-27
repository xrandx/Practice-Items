#include <stdio.h>
#include <stdlib.h>

typedef struct tag_stackelem
{
	int num;
	tag_stackelem *next;
} stack;

void LoopCLS();
int IsEmpty(stack *s);


stack* Push(stack *s)
{
	stack *tmp = s;
	s = (stack*)malloc(sizeof(stack));
	printf("请输入数据元素:");
	scanf("%d", &s->num);
	s->next = tmp;
	return s;
}

stack* Pop(stack *s)
{
	stack* tmp;
	tmp = s->next;
	printf("%d", s->num);
	free(s);
	s = tmp;
}

void View(stack *s)
{
	int i = 1;
	printf("0 ---> Top\n");
	while(s)
	{
		printf("%d ---> %d\n", i++, s->num);
		s = s->next;
	}
}

stack* Destroy(stack *s)
{
	free(s);
	return NULL;
}

int count (stack *s)
{
	int i = 0;
	stack *p;
	p = s;
	while(p)
	{
		p = p->next;
		i++;
	}
	return i;
}
void menu()
{
	printf("1.Push栈元素\n");
	printf("2.Pop栈元素\n");
	printf("3.Top栈元素\n");
	printf("4.查看元素个数\n");
	printf("5.浏览所有元素\n");
	printf("\n0.清空所用内存并退出\n");
}


int main()
{
	int op;
	stack *s = NULL;
	printf("初始化成功.\n");
	while(1)
	{
		menu();
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				system("cls");
				s = Push(s);
				break;
			case 2:
				system("cls");
				s = Pop(s);
				break;
			case 3:
				system("cls");
				printf("%d\n", s->num);
				break;
			case 4:
				system("cls");
				printf("元素个数为 %d 个\n", count(s));
				break;
			case 5:
				system("cls");
				View(s);
				break;
			case 0:
				system("cls");
				s = Destroy(s);
				exit(1);
			default:
				system("cls");
				break;
		}
		LoopCLS();
	}

	return 0;
}

int IsEmpty(stack *s)
{
	//return(s->next? 0 : 1);
	return s->next == NULL;
}

void LoopCLS()
{
	getchar();
	printf("\n回车以返回菜单。\n");
	while(getchar()!='\n');
	system("cls");
	return;
}
