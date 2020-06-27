#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 1000 + 6;
int dfs_clock, n, m, top;
int deg[maxn], pre[maxn], low[maxn];
int stakk[maxn];
vector<int> G[maxn];
stack<int> s;

void dfs(int u, int fa)
{
    low[u] = pre[u] = ++dfs_clock;
    s.push(u);
    stakk[top++] = u;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!pre[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
//            if(lowv >= pre[u])
//            {
//                  ...
//            }
        }
        else if(pre[v] < pre[u] && v != fa)
        {
            low[u] = min(low[u], pre[v]);
        }
    }
    if(pre[u] == low[u]) //u不一定是割点
    {
        while (top > 0 && stakk[top] != u)
        {
            low[stakk[--top]] = low[u];
        }

//        while(!s.empty() && s.top() != u) 
//        {
//            low[s.top()] = low[u];
//            s.pop();
//        }
    }
//    if(fa < 0 && child == 1) iscut[u] = 0;
}



void find_bcc()
{
    memset(low, 0, sizeof(low));
    memset(deg, 0, sizeof(deg));
    memset(pre, 0,sizeof(pre));
    top = dfs_clock = 0;
    for(int i = 1; i <= n; i++)
        if(!pre[i]) dfs(i, -1);
}

int main()
{
//    freopen("in.txt", "r", stdin);
    while(scanf("%d%d", &n, &m) != EOF)
    {
//        cout << n << m<<endl;
        int u, v;
        for (int i = 1; i <= n; i++) G[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
//            cout << u << " " << v << endl;
        }
        while(!s.empty()) s.pop();
        find_bcc();
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < G[i].size(); j++)
            {
                if(low[i] != low[G[i][j]])
                {
                    deg[low[i]]++;
                    deg[low[G[i][j]]]++;
                }
            }
        }
        for(int i = 1; i <= n; i++)
            if(deg[i] / 2 == 1) ans++;//出度加入度/2  连通分量的度等于1 叶子结点
        printf("%d\n", (ans + 1) / 2);
    }
    return 0;
}
