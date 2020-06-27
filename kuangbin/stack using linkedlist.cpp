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
	printf("����������Ԫ��:");
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
	printf("1.PushջԪ��\n");
	printf("2.PopջԪ��\n");
	printf("3.TopջԪ��\n");
	printf("4.�鿴Ԫ�ظ���\n");
	printf("5.�������Ԫ��\n");
	printf("\n0.��������ڴ沢�˳�\n");
}


int main()
{
	int op;
	stack *s = NULL;
	printf("��ʼ���ɹ�.\n");
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
				printf("Ԫ�ظ���Ϊ %d ��\n", count(s));
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
	printf("\n�س��Է��ز˵���\n");
	while(getchar()!='\n');
	system("cls");
	return;
}
