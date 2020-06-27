#define NULL -1
#include <stdio.h>

typedef struct tagnode
{
	int *addr;
	int data;
	int *next;
}lnode;

int main()
{

	int *h, n, k;
	while(~scanf("%d %d %d", &h, &n, &k))
	{
		lnode L;
		int *p;
		int i;
		p = h;
		for(i=0; i<n; i++)
		{
			p = p->next;
		}
	}
	return 0;
}
