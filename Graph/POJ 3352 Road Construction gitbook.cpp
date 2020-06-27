#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MEM(a) memset(a, 0, sizeof(a))
#define pb push_back
const int maxv = 1010;

int pre[maxv], low[maxv], deg[maxv], stakk[maxv];
int dfs_clock, top;
vector<int> G[maxv];

void dfs(int u, int fa) {
    low[u] = pre[u] = ++dfs_clock;
    stakk[top++] = u;
    for (int i = 0; i < (int)G[u].size(); i++)
    {
        int v = G[u][i];
        if (!pre[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (pre[v] < pre[u] && v != fa)
        {
            low[u] = min(low[u], pre[v]);
        }
    }
    if (pre[u] == low[u])
    {
        while (top > 0 && stakk[top] != u)
        {
            low[stakk[--top]] = low[u];
        }
    }
}

void find_bcc(int n) {
    MEM(pre); MEM(low);MEM(deg);
    dfs_clock = top = 0;
    for (int i = 1; i <= n; i++)
        if (!pre[i]) dfs(i, -1);
}
int main() {
    int n, m, u, v;
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) G[i].clear();

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            G[u].pb(v); G[v].pb(u);
        }
        find_bcc(n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (int)G[i].size(); j++) {
                if (low[i] != low[G[i][j]]) {
                    deg[low[i]]++;
                    deg[low[G[i][j]]]++;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            if (deg[i]/2 == 1) ans++;
        printf("%d\n", (ans+1)/2);
    }
    return 0;
}
