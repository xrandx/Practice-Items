#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const int maxn = 1006;
const int maxm = 26;
int a[maxm];

int main()
{
	int n, m;
	while(~scanf("%d", &n))
	{
		while(n--)
		{
			scanf("%d", &m);
			for(int i = 0; i < m; i++)
			{
				cin >> a[i];
			}
			int num = 0;
			for(int i = 0; i < 1006; i++)
			{
				num = 0;
				int k = a[0];
				for(int j = 0; j < m - 1; j++)
				{
					a[j] = abs(a[j] - a[j + 1]);
					if(a[j] == 0)
						num++;
				}
				a[m - 1] = abs(k - a[m - 1]);
				if(a[m - 1] == 0)
				{
					num++;
					if(num == m)
						break;
				}
			}
			if(num == m)
				cout << "ZERO" << endl;
			else
				cout << "LOOP" << endl;
		}
	}
}
