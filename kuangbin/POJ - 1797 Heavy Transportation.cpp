#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1006;

int n, m;
int w[maxn][maxn];
int vis[maxn];
int d[maxn];


void dijkstra()
{
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
        d[i] = w[1][i];
//	vis[1] = 1;
	for(int i = 1; i <= n; i++)
	{
		int x, maxx = -1;
		for(int y = 1; y <= n; y++)
		{
			if(!vis[y] && maxx < d[y])
				maxx = d[x = y];
		}
		if(x == -1) break;
		vis[x] = 1;
		for(int y = 1; y <= n; y++)
		{
//			if(!vis[y])
			d[y] = max(d[y], min(w[x][y], d[x]));
			
//			if(!vis[y])
//            {
//                int mmin = min(maxx, w[y][x]);
//                if(mmin > d[y])
//                {
//                    d[y] = mmin;
//                }
//            }

		}
	}
}


int main()
{
//	freopen("in.txt", "r", stdin);
	int kase = 0;
	int t;
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d%d", &n, &m);
		memset(w, 0, sizeof(w));
		for(int i = 1; i <= m; i++)
		{
			int u, v, tmp;
			scanf("%d%d%d", &u, &v, &tmp);
			w[u][v] = w[v][u] = tmp;
		}
		dijkstra();
		printf("Scenario #%d:\n%d\n\n", ++kase, d[n]);
	}
	return 0;
}
