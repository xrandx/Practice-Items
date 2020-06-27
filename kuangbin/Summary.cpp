#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
set<int> seta;
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		ll a[n];
		ll sum = 0;
		seta.clear();
		for(int i = 0; i < n; i++)
			scanf("%I64d", &a[i]);
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				seta.insert(a[i] + a[j]);
			}
		}
		for(set<int>::iterator it = seta.begin(); it != seta.end(); it++)
		{
			sum += *it;
		}
		cout << sum << "\n";
	}
	return 0;
}
