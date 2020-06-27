#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10006;

int main()
{
	int n, m, k = 1;
	while(~scanf("%d %d", &n, &m) && n && m)
	{
		int a[maxn];
		memset(a, 0, sizeof(a));
		printf("CASE# %d:\n", k++);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		for(int i = 0; i < m; i++)
		{
			int tmp;
			cin >> tmp;
			int loc = lower_bound(a, a+n, tmp) - a;
			if(a[loc] == tmp)
				printf("%d found at %d\n", tmp, loc + 1);
			else
				printf("%d not found\n", tmp);
		}
	}
}
