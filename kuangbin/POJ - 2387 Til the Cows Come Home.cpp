#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1006;
const int maxe = 2006;
const int INF = 0x3f3f3f3f;

int n, t;
int map[maxn][maxn];
int d[maxn], vis[maxn];


void dijkstra()
{
	d[1] = 0;
	for(int i = 0; i <= n; i++)
	{
		int x, m = INF;
		for(int y = 1; y <= n; y++)
			if(m >= d[y] && !vis[y])
				m = d[x = y];
		vis[x] = 1;
		for(int y = 1; y <= n; y++)
			d[y] = min(d[y], d[x] + map[x][y]);

	}
}

int main()
{
//	freopen("in.txt", "r", stdin);
	int u, v, w;
	while(~scanf("%d%d", &t, &n))
	{
		memset(map, 0x3f, sizeof(map));
		memset(vis, 0, sizeof(vis));
		memset(d, 0x3f, sizeof(d));
		for(int i = 0; i < t; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			if(w < map[u][v])
			{
				map[u][v] = w;
				map[v][u] = w;
			}
		}
		dijkstra();
		printf("%d\n", d[n]);
	}
	return 0;
}
