#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define null -1

typedef struct tag_btree
{
	char ch;
	int left, right;
} bt, *btptr;

int FindRoot(btptr t, int num )
{
	int i;
	int T[num];
	memset(T, 0, num);
	for(i=0; i < num; i++)
	{
		if(t[i].left != null)
			T[t[i].left] = 1;
		if(t[i].right != null)
			T[t[i].right] = 1;
	}
	for(i=0; i<num; i++)
	{
		if(!T[i]) break;
	}
	return i;
}

int Isomorphism(btptr t1, int r1, btptr t2, int r2)
{
	if(r1 == null && r2 == null)
		return 1;
	if((r1 == null && r2 != null) || (r1 != null && r2 == null))
		return 0;
	if(t1[r1].ch != t2[r2].ch)
		return 0;

	if(t1[r1].left == null && t2[r2].left == null)
		return Isomorphism(t1, t1[r1].right, t2, t2[r2].right);

	if((t1[r1].left != null) && (t2[r2].left != null) &&
	        (t1[t1[r1].left].ch == t2[t2[r2].left].ch ))
	{
		return (Isomorphism(t1, t1[r1].left, t2, t2[r2].left) &&
		        Isomorphism(t1, t1[r1].right, t2, t2[r2].right));
	}
	else
	{
		return (Isomorphism(t1, t1[r1].left, t2, t2[r2].right) &&
		        Isomorphism(t1, t1[r1].right, t2, t2[r2].left));
	}
}

int main()
{
	int n;
	int num1, num2;
	while( ~scanf("%d",&n))
	{
		bt t1[n];
		char ch;
		num1 = n;
		if(num1 == 0)
		{
			printf("No\n");
			continue;
		}
		getchar();
		int i = 0;
		while(n--)
		{
			t1[i].ch= getchar();
			getchar();
			ch = getchar();
			t1[i].left = ch == '-' ? null : atoi(&ch);
			getchar();
			ch = getchar();
			t1[i].right = ch == '-' ? null : atoi(&ch);
			getchar();
			i++;
		}
		scanf("%d",&n);
		num2 = n;
		if(num1 != num2)
		{
			printf("No\n");
			continue;
		}
		
		bt t2[n];
		getchar();
		i = 0;
		while(n--)
		{
			t2[i].ch= getchar();
			getchar();
			ch = getchar();
			t2[i].left = ch == '-' ? null : atoi(&ch);
			getchar();
			ch = getchar();
			t2[i].right = ch == '-' ? null : atoi(&ch);
			getchar();
			i++;
		}
		int r1, r2;
		r1 = FindRoot(t1, num1);
		r2 = FindRoot(t2, num1);
		if(Isomorphism(t1, r1, t2, r2))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}

