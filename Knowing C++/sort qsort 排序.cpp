#include<iostream>
#include<cstdio>
#include<cstdlib>


int cmp(const void *a, const void *b)
{
	int *p1, *p2;
	p1 = (int*)a;
	p2 = (int*)b;
	return (*p1 - *p2);
}
using namespace std;
int main()
{
	int a[105];
	for(int i = 0; i < 100; i++)
	{
		a[i] = 100 - i;
	}
	//sort(a, a+100);
	qsort(a, 100,sizeof(int), cmp);
	for(int i = 0; i < 100; i++)
	{
		cout << a[i] << '\t';
	}
}
