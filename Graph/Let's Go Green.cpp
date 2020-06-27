#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100006;
const int maxm = 200005;
int first[maxn];
int cnt;
int sum;
//int temp[maxn];
struct Edge
{
    int v, w, next;
} edges[maxm];


void dfs(int u, int fa)
{
    int esum = 0;
    int maxw = 0;
    for(int j = first[u]; j != -1; j = edges[j].next )
    {
        int v = edges[j].v;
        esum += edges[j].w;
        maxw = max(maxw, edges[j].w);
        if(v != fa)
            dfs(v, u);
    }
    if(maxw >= esum - maxw)
        sum -= (esum - maxw);
    else sum -= esum / 2;
}



void add(int& u, int& v, int& w)
{
    edges[cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].next = first[u];
    first[u] = cnt++;
}


int main()
{
//    freopen("in.txt", "r", stdin);
    int t, kase = 1;
    int n, res, msum;
    int u, v, w;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
//        memset(first, -1, sizeof(first));
        for(int i = 0; i <= n; i++) first[i] = -1;
        cnt = sum = 0;
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
            sum += w;
        }

//        res = 0;
//        for(int i = 1;i <= n; i++)
//        {
//            msum = cnt = 0;
//            int maxw = -1;
//            for(int j = first[i]; j != -1; j = edges[j].next)
//            {
//                maxw = max(maxw, edges[j].w);
//                msum += edges[j].w;
//            }
//            if(2 * maxw >= msum) res+= maxw;
//            else res += (msum + 1) / 2;
//        }
//        printf("Case #%d: %d\n", kase++, res - sum);
        dfs(1, -1);
        printf("Case #%d: %d\n", kase++, sum);
    }
    return 0;
}
