#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;
int n, cnt;
const int maxn = 1e5 + 6;
int dp[maxn];
int vis[maxn];
long long ans;

struct Edge
{
    int u, v, w, next;
} edges[2 * maxn];
int first[maxn];
//struct Edge
//{
//    int v, w;
//    Edge(int v, int w): v(v), w(w){}
//}edges;

void add(int& u, int& v, int& w)
{
    edges[cnt].u = u;
    edges[cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].next = first[u];
    first[u] = cnt;
    cnt++;
}

//void dfs(int u,int pre)
//{
//    for(int i = first[u];i!=-1;i=edges[i].next)
//    {
//        int v=edges[i].v;
//        if(v==pre)continue;
//        dfs(v,u);
//        dp[u]+=dp[v];
//        ans+=(long long)edges[i].w * (long long)min(dp[v],n-dp[v]);
//    }
//    dp[u]++;
//}


void dfs()
{
    stack<int> s;
    s.push(1);
    vis[1] = 1;
    while(!s.empty())
    {
        int fa = s.top();
        bool flag = false;
        for(int i = first[fa]; i != -1; i = edges[i].next)
        {
            int& v = edges[i].v;
            if(vis[v]) continue;
            s.push(v);
            vis[v] = 1;
            flag = true;
        }
        if(flag) continue;
        s.pop();
        for(int i = first[fa]; i != -1; i = edges[i].next)
        {
            int v = edges[i].v;
            if(dp[v] != 0)
            {
                dp[fa] += dp[v];
                ans += (long long) edges[i].w * (long long)min(dp[v], n - dp[v]);
            }
        }
        dp[fa]++;
    }

}

int main()
{
//    freopen("in.txt", "r", stdin);
    int t, kase = 0;
    int u, v, w;
    scanf("%d", &t);
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        memset(first, -1, sizeof(first));
        ans = 0;
        cnt = 0;
        scanf("%d", &n);
//        cout << "n" << n << endl;
//        for(int i = 0; i < n; i++)
//            g[i].clear();
        for(int i = 0; i < n-1; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        dfs();
//        for(int i = 1; i <= n - 1; i++)cout << g[i][0].v << endl;
        printf("Case #%d: %lld\n", ++kase, ans * 2);
    }
    return 0;
}
