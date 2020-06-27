#include <stdio.h>
#include <stdlib.h>

typedef struct tag_table
{
	int ori;
	int a3;
	int a2;
	int a1;
	int a0;
	int flag;
} table;

void compare(table tb[], table all[], int n)
{
	int tmp;
	all[n].flag = 0;
	for(int i=0; i<68; i++)
	{
		tmp = 0;
		tmp = (all[n].a3 == tb[i].a3)?  tmp + 1 : tmp;
		tmp = (all[n].a2 == tb[i].a2)?  tmp + 1 : tmp;
		tmp = (all[n].a1 == tb[i].a1)?  tmp + 1 : tmp;
		tmp = (all[n].a0 == tb[i].a0)?  tmp + 1 : tmp;
		if(tmp == 3)
			all[n].flag++;
	}
	return;
}


int main()
{
	table tb[68];
	for(int i=0; i<68; i++)
	{
		tb[i].ori = (i + 32) * (i + 32);
		tb[i].a3 = tb[i].ori / 1000 % 10;
		tb[i].a2 = tb[i].ori / 100 % 10;
		tb[i].a1 = tb[i].ori / 10 % 10;
		tb[i].a0 = tb[i].ori / 1 % 10;
	}

	int n;
	while(~scanf("%d", &n))
	{
		table all[n];
		for(int i=0; i<n; i++)
		{
			scanf("%d", &all[i].ori);
			all[i].a3 = all[i].ori / 1000 % 10;
			all[i].a2 = all[i].ori / 100 % 10;
			all[i].a1 = all[i].ori / 10 % 10;
			all[i].a0 = all[i].ori / 1 % 10;
			compare(tb, all, i);
		}
		for(int i=0; i<n; i++)
		{
			printf("Case %d: ",i+1);
			printf("%d\n",all[i].flag);
		}
	
	}

	return 0;
}
