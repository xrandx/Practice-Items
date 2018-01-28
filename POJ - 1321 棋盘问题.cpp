#include <cstdio>
#include <cstring>
const int maxn = 10;
int m[maxn][maxn];
int n, k;
long long ans;
int vis[maxn];

void dfs(int p, int cnt)
{
	if(cnt == 0) 
	{
		ans++;
		return;
	}
	else if(p > n) return;
	for(int i = 1; i <= n; i++)
	{
		if(m[p][i] == 1)
		{
			if(vis[i] == 0)
			{
				vis[i] = 1;
				dfs(p + 1, cnt - 1);
				vis[i] = 0;
			}
		}
	}
	dfs(p + 1, cnt);
	return;
}

/*
int dfs(int 2, int 1)
{
	if(p > n) return 0;
	if(cnt == 0) return 1;
	
	for(int i = 1; i <= n; i++)
	{
		if(m[p][i] == 1)
		{
			if(vis[i] == 0)
			{
				ans += dfs(i + 1, cnt);
				vis[i] = 1;
				ans += dfs(i + 1, cnt - 1);
			}
		}
	}
}
*/

int main()
{
//	freopen("in.txt", "r", stdin);
	while(scanf("%d%d", &n, &k) != EOF && n != -1)
	{
		getchar();
		memset(m, 0, sizeof(m));
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				char ch = getchar();
//				printf("%c", ch);
				if(ch == '#')
					m[i][j] = 1;
			}
//			printf("\n");
			getchar();
		}
		dfs(1, k);
		printf("%I64d\n", ans);
	}
	return 0; 
}
