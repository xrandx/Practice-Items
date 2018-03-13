#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 20;

bool tmp[maxn][maxn], g[maxn][maxn], count[maxn][maxn];
int n, m, ans, p, cnt;
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};


void flip(int u, int v)
{
	tmp[u][v] ^= 1;
	count[u][v] = 1;
	cnt++;
	for(int i = 0; i < 4; i++)
	{
		if(u + x[i] >= 0 && v + y[i] >= 0)
		{
			tmp[u + x[i]][v + y[i]] ^= 1;
		}
	}
}

bool yep(int k)
{
	cnt = 0;
	memcpy(tmp, g, sizeof(tmp));
	
	for(int i = 0; i < m; i++)
	{
		if(k & (1 << i)) flip(0, i);
	}
	
	for(int i = 1; i < n; i++)
		for(int j = 0; j < m; j++)
			if(tmp[i - 1][j]) flip(i, j);
	for(int i = 0; i < m; i++)
		if(tmp[n - 1][i]) return false;
	return true;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	while(~scanf("%d%d", &n, &m))
	{
		memset(g, 0, sizeof(g));
		p = -1;
		ans = n * m + 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &g[i][j]);
		for(int i = 0; i < (1 << m); i++)
		{
			if(yep(i) && ans > cnt)
				ans = cnt, p = i;
		}
		if(p >= 0)
		{
			memset(count, 0, sizeof(count));
			yep(p);
			for(int i = 0; i < n; i++)
			{
				int j = 0;
				for(;j < m - 1; j++)
				{
					printf("%d ", count[i][j]);
				}
				printf("%d\n", count[i][j]);
			}
		}
		else puts("IMPOSSIBLE");
	}
	return 0;
}
