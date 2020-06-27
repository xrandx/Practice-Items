#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

void Swap(ll *a, ll *b)
{
	ll tmp = *b;
	*b = *a;
	*a = tmp;
}
ll median3(ll a[], int n)
{
	ll right = n, left = 0, center = (left + right) / 2;
	if(a[left] > a[center])
		Swap(&a[left], &a[center])
}

void quicksort(ll a[], int n)
{
	ll pivot = median3(a, n);
	
}
int main()
{
	int n;
	while(~scanf("%d", &n) && n)
	{
		ll a[n];
		for(int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
		}
		quicksort(a, n);
		
	}
}

