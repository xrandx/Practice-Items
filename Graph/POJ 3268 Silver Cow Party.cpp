#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1006;
const int INF = 0x3f3f3f3f;
int m1[maxn][maxn], m2[maxn][maxn], vis[maxn];
int n, m, x;

void dijkstra(int (* m)[maxn], int d[])
{
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
        d[i] = m[x][i];
    vis[x] = 1;

    for(int i = 1; i <= n; i++)
    {
        int flag, minn = INF;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j] && minn >= d[j])
                minn = d[flag = j];
        }
        vis[flag] = 1;
        for(int j = 1; j <= n; j++)
        {
            if(d[j] > d[flag] + m[flag][j])
            {
                d[j] = d[flag] + m[flag][j];
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d%d", &n, &m, &x))
    {
        memset(m1, 0x3f, sizeof(m1));
        memset(m2, 0x3f, sizeof(m2));
        for(int i = 1; i <= m; i++)
        {
            int u, v, t;
            scanf("%d%d%d", &u, &v, &t);
            m1[u][v] = t;
            m2[v][u] = t;
        }
        int d1[maxn], d2[maxn];
        dijkstra(m1, d1);
        dijkstra(m2, d2);
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i != x)
                ans = max(ans, d1[i] + d2[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

