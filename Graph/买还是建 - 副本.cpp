#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxq = 1000000;
const int maxn = 1006;
const int INF = 0x3f3f3f3f;

struct sub
{
    int sum, cost;
    vector<int> list;
} suit[10];

struct edge
{
    int u, v, cost;
    bool operator < (const edge& rhs) const
    {
        return cost < rhs.cost;
    }
};

int x[maxn], y[maxn], p[maxn];
edge e[maxq];

int findset(int x)
{
    return p[x] == x? x : p[x] = findset(p[x]);
}

void reset(int n)
{
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int t, n, q, f;
    scanf("%d", &t);
    f = t;
    while(t--)
    {
        scanf("%d%d", &n, &q);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &suit[i].sum, &suit[i].cost);
            suit[i].list.clear();
            for(int j = 0; j < suit[i].sum; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                suit[i].list.push_back(tmp);
            }
        }
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &x[i], &y[i]);
        //造边
        int ecnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                e[++ecnt].u = i;
                e[ecnt].v = j;
                e[ecnt].cost = ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) );
            }
            for(int j = i + 1; j <= n; j++)
            {
                e[++ecnt].u = i;
                e[ecnt].v = j;
                e[ecnt].cost = ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) );
            }
        }
        sort(e + 1, e + ecnt + 1);
//        for(int i = 1; i <= n - 1; i++)
//            cout << e[i].u << " " << e[i].v  << " " << e[i].cost << endl;
        edge after[n];
        LL ans = 0;
        int ecnt2 = 0;
        reset(n);
        int meta, meta2;
        for(int i = 1; i <= ecnt; i++)
        {
            meta = findset(p[e[i].u]);
            meta2 = findset(p[e[i].v]);
            if(meta2 != meta)
            {
                p[meta2] = meta;
                ans += e[i].cost;
                after[++ecnt2] = e[i];
            }
            if(ecnt2 == n - 1)
                break;
        }

        LL _ans;
        for(int i = 0; i < (1 << q); i++)
        {
            reset(n);
            _ans = 0;
            ecnt2 = n;
            for(int j = 0; j < q; j++)
            {
                if(i & (1 << j))
                {
                    for(int k = 1; k < suit[j].sum; k++)
                    {
                        meta = findset(suit[j].list[0]);
                        meta2 = findset(suit[j].list[k]);
                        if(meta != meta2)
                        {
                            p[meta2] = meta;
                            ecnt2--;
                        }
                    }
                    _ans += suit[j].cost;
                }
            }
            for(int k = 1; k <= n - 1; k++)
            {
                meta = findset(after[k].u);
                meta2 = findset(after[k].v);
                if(meta != meta2)
                {
                    _ans += after[k].cost;
                    p[meta2] = meta;
                    ecnt2--;
                    if(ecnt2 == 1)
                        break;
                }
            }
//            cout << "_ans:" << _ans << " ans" << ans << endl;
            if(ecnt2 == 1)
            {
                ans = min(_ans, ans);
            }

        }

        cout << ans << "\n";
        if(t) cout << "\n";
    }

}

