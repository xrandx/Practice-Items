#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10000 + 6;

int u[maxn], v[maxn], r[maxn], w[maxn], p[maxn];
int cmp(const int i, const int j)
{
    return w[i] < w[j];
}

int find(int x)
{
    // return p[x] == x ? x : find(p[x]);//查
    return p[x] == x ? x : p[x] = find(p[x]); //并查集
}

int main()
{
//     freopen("in.txt", "r", stdin);
    int n, m;
    while(~scanf("%d %d", &n, &m) && (n || m))
    {
        int minn = INF;
        for(int i = 1; i <= m; i++) // 边的排列序号
            r[i] = i;
        for(int i = 1; i <= m; i++ )
            scanf("%d %d %d", &u[i], &v[i], &w[i]);
        sort(r + 1, r + m + 1, cmp);
        for(int i = 1; i <= m; i++)
        {
            for(int h = 1; h <= n; h++) //并查集重置
                p[h] = h;
            int j, cnt = 0;
            for(j = 0; j + i <= m; j++)
            {
                int num = r[i + j];
                int x = find(u[num]);
                int y = find(v[num]);
                if(x != y)
                {
                    p[x] = y;
                    cnt++;
                }
                if(cnt == n - 1)
                    break;
            }
            if(cnt == n - 1)
                minn = min(minn, w[r[j + i]] - w[r[i]]);
        }
        if(minn == INF)
            cout << "-1\n";
        else
            cout << minn << "\n";
    }
}
