#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1010
#define M 1010
#define INF 0x3f3f3f3f

int n,tot;
int head[N];
struct edge
{
    int u,v,next;
}e[2*M];
int dfn[N],low[N],vis[N],dcnt,bcnt,de[N];

inline int min(int x , int y)
{
    return x<y ? x:y;
}

void add(int u ,int v ,int k)
{
    e[k].u = u; e[k].v = v;
    e[k].next = head[u]; head[u] = k++;
    u = u^v; v = u^v; u = u^v;
    e[k].u = u; e[k].v = v;
    e[k].next = head[u]; head[u] = k++;
}

void dfs(int u ,int fa)
{
    dfn[u] = low[u] = ++dcnt;
    vis[u] = 1;
    for(int k=head[u]; k!=-1; k=e[k].next)
    {
        int v = e[k].v;
        if(v == fa) continue;
        if(!vis[v]) //树边
        {
            dfs(v,u);
            low[u] = min(low[u] , low[v]);
        }
        else if(vis[v] == 1) //后向边
            low[u] = min(low[u] , dfn[v]);
        //如果是横叉边为vis[v] == 2 , 跳过
    }
    vis[u] = 2;
}

void solve()
{
    memset(dfn,0,sizeof(dfn));
    memset(de,0,sizeof(de));
    memset(vis,0,sizeof(vis));
    dcnt = bcnt = 0;
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i,i);
    for(int u=1; u<=n; u++)
        for(int k=head[u]; k!=-1; k=e[k].next)
        {
            int v = e[k].v;
            if(low[u] != low[v]) //属于不同的边连通分量
                de[low[u]]++;
        }
    int leaf = 0;
    for(int i=1; i<=n; i++)
        if(de[i] == 1)
            leaf++;
    cout << (leaf+1)/2 << endl;
}

int main()
{
    while(cin>> n >> tot)
    {
        int u,v,k = 0;
        memset(head,-1,sizeof(head));
        for(int i=0; i<tot; i++,k+=2)
        {
            cin >> u >> v;
            add(u,v,k);
        }
        solve();
    }
    return 0;
}
