#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;

const int maxn = 755;
int a[maxn][maxn];

int cmp(const void *a, const void *b)
{
	int* x = (int*)a;
	int* y = (int*)b;
	return (*x - *y);
}


int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
			qsort(a[i], n, sizeof(a[i]), cmp);
		}
		
	}
}
