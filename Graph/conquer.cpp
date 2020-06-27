#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 200000 + 6;
int n;
ll sum[maxn], cnt[maxn];
int pa[maxn];
struct Edge
{
    int a, b, c;
    bool operator < (const Edge& rhs) const
    {
        return c > rhs.c;
    }
};
Edge edges[maxn];
void reset()
{
    for(int i = 1; i <= n; i++)
    {
        pa[i] = i;
        cnt[i] = 1;
    }
}

int findset(int x)
{
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
//    int r = x;
//    while(pa[r] != r)
//        r = pa[r];
//    pa[x] = r;
//    return r;
}

void kruskal()
{
    sort(edges, edges + n - 1);
    memset(sum, 0, sizeof(sum));
    reset();
    ll ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int u = findset(edges[i].a);
        int v = findset(edges[i].b);
        ll Wu = sum[u] + edges[i].c * cnt[v];
        ll Wv = sum[v] + edges[i].c * cnt[u];
        if(Wu > Wv)
        {
            pa[v] = u;
            cnt[u] += cnt[v];
            sum[u] = Wu;
            ans = sum[u];
        }
        else
        {
            pa[u] = v;
            cnt[v] += cnt[u];
            sum[v] = Wv;
            ans = sum[v];
        }
//        if(u != v)
//        {
//            for(int j = 1; j <= n; j++)
//            {
//                if(pa[j] == u)
//                    sum[j] += edges[i].c;
//            }
//            pa[v] = u;
//        }
    }
    cout << ans << "\n";
    return;
}



int main()
{
//    freopen("in.txt", "r", stdin);
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].c);
        }

//        for(int i = 0; i < n - 1; i++) cout << edges[i].c <<endl;
        kruskal();
    }

    return 0;
}

