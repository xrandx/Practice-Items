#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 6000 + 6;
int n;
int w[maxn];
int dp[maxn][2];
vector<int> g[maxn];

int dfs(int x, int s, int fa)
{
    if(dp[x][s] != -1)
        return dp[x][s];
    dp[x][s] = 0;
    if(s == 1)
    {
        dp[x][s] = w[x];
        for(int i = 0; i < g[x].size(); i++)
        {
            if(fa != g[x][i])
            {
                dp[x][s] += dfs(g[x][i], 0, x);
            }
        }
    }
    else
    {
        for(int i = 0; i < g[x].size(); i++)
        {
            if(fa != g[x][i])
            {
                dp[x][s] += max(dfs(g[x][i], 0, x), dfs(g[x][i], 1, x));
            }
        }
    }
    return dp[x][s];
}

int main()
{
//    freopen("in.txt", "r", stdin);
    while(~scanf("%d", &n))
    {
        memset(w, 0, sizeof(w));
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &w[i]);
            g[i].clear();
        }
        int u, v;
        while(1)
        {
            scanf("%d%d", &u, &v);
            if(u + v == 0) break;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        int ans = max(dfs(1, 0, -1), dfs(1, 1, -1));
        printf("%d\n", ans);
    }
    return 0;
}
