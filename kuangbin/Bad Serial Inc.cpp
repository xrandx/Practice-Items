#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

inline int sumbit(int a[], int n)
{
	int sum = 0;
	for(int i = n; i >= 0; i--)
	{
		sum += a[i] * pow(10, i);
	}
	return sum;
}

int main()
{
	int n, m;
	while(~scanf("%d %d", &n, &m) && n > 0 && m > 0)
	{
		int a[n];
		
	}
}
