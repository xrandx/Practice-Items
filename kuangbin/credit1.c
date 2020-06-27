#include <stdio.h>
#include <stdlib.h>

typedef struct classes
{
	double credit;
	double score;
	struct classes *next;
} cls;

int main()
{
	int i = 0;
	cls *head, *tail, *ptr;
	head = (cls *)malloc(sizeof(cls));
	tail = head;


	printf("\n往学分栏输入负数终止并计算。\n");

	while(1)
	{
		ptr = (cls *)malloc(sizeof(cls));
		printf("\n== 第%d门 ==\n", ++i);
		printf("学分:");
		scanf("%lf",&ptr->credit);

		if(ptr->credit < 0)
		{
			tail->next = NULL;
			free(ptr);
			break;
		}
		printf("对应成绩:");
		scanf("%lf",&ptr->score);

		tail->next = ptr;
		tail = ptr;

	}

	ptr = head->next;
	double sum = 0, s = 0;
	i = 0;

	while(ptr)
	{
		sum += ptr->credit;
		s += ptr->score * ptr->credit;
		ptr = ptr->next;
	}
	printf("\n学分为%.2lf\n", s/sum*1.0);

	int n = 1;
	while(n)
	{
		printf("\n输入负数终止程序:");
		scanf("%d",&n);
		if(n < 0)
		{
			n = 0;
			break;
		}

		else
			n = 1;
	}
	head = ptr;
	while(ptr)
	{
		tail = ptr->next;
		free(ptr);
		ptr = tail;
	}
	return 0;
}
