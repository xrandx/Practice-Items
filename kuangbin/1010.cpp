#include <stdio.h>
#include <stdlib.h>
typedef struct tagarray
{
	int num;
	int a[100000];
	int finalnum;
	int final[100000];
	int devia;
	struct tagarray *next;
} ary;

int main()
{
	int t;
	int i;
	ary *head, *p, *tail;
	head = (ary*)malloc(sizeof(ary));
	tail = head;
	while(~scanf("%d", &t))
	{
		int t2 = t;
		while(t--)
		{
			p = (ary*)malloc(sizeof(ary));
			tail->next = p;
			tail = p;
			p->devia = 0;
			scanf("%d",&p->num);
			for(i=0; i<p->num; i++)
			{
				scanf("%d",&p->a[i]);
			}
			//第一个
			if(p->a[1] >= p->a[0])
			{
				p->final[0 - p->devia] = p->a[0];
			}
			else
			{
				p->devia++;
			}


			for(i=1; i<p->num-1; i++)
			{
				if(p->a[i] >= p->a[i-1] && p->a[i] <= p->a[i+1])
				{
					p->final[i - p->devia] = p->a[i];
				}
				else
				{
					p->devia++;
				}

			}
			//最后一个 
			if(p->a[p->num-2] <= p->a[p->num - 1])
			{
				p->final[p->num - 1 - p->devia] = p->a[p->num - 1];
			}
			else
			{
				p->devia++;
			}
			p->finalnum = p->num - p->devia;
		}
		tail->next = NULL;


		p = head->next;
		printf("%d\n", t2);
		while(p)
		{
			if(p->finalnum != 0)
			{
				printf("%d\n", p->finalnum);
				for(i=0; i < p->finalnum; i++)
				{
					printf("%d ",p->final[i]);
				}
				printf("\n");
			}
			else
			{
				printf("0\n\n");
			}
			p = p->next;
		}

		free(head); 
	}
	return 0;
}
