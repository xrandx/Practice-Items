#include <stdio.h>
int main()
{
	int n;
	printf("输入几个数？");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int flag = 0;
	int max;
	int tmp;
	for(int start = 0; start < n; start++)
	{
		max = a[start];
		if(start+1 == n) break;
		for(int j = start + 1 ; j < n; j++)
		{
			if(max < a[j])
			{
				max = a[j];
				flag = j;
			}
		}
		tmp = a[start];
		a[start] = max;
		a[flag] = tmp;
	}
	for(int i = 0; i<n; i++)
	{
		printf("%d ",a[i]);
	}


}
