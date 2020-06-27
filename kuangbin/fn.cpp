#include<cstdio>
int fn(int n)
{
	int m;
	if(n==1 || n==2)
		return 1;
	return fn(n-2)+fn(n-1);
}

int main()
{
	int t;
	for(t=1; t<=20; t++)
	{
		printf("%-8d\n",fn(t));
		if(t%5==0)
			printf("\n");
	}
	for(t=2; t<=20; t++)
	{
		printf("%lf\n",double(fn(t-1))/double(fn(t)));
		if(t%5==0)
			printf("\n");
	}
	return 0;
}

