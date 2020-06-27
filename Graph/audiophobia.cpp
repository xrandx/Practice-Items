#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
const int maxn = 106;
const int INF = 0x3f3f3f3f;
int d[maxn][maxn];

inline void redist(int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            d[i][j] = INF;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int c, s, q;
    int kase = 1;


    while(~scanf("%d%d%d", &c, &s, &q) && (c || s || q))
    {
        int u, v, inten;
        redist(c);
//        memset(d, 0, sizeof(d));
        for(int i = 1; i <= s; i++)
        {
            scanf("%d%d%d", &u, &v, &inten);
//            cout << u << " = u  " << v << " = v " << inten << endl;
            d[u][v] = inten;
            d[v][u] = inten;
        }
        for(int k = 1; k <= c; k++)
            for(int i = 1; i <= c; i++)
                for(int j = 1; j <= c; j++)
        {
            d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
        }
        if(kase != 1) cout << "\n";
        cout << "Case #" << kase++ << "\n";
        for(int i = 1; i <= q; i++)
        {
            scanf("%d%d", &u, &v);
            if(d[u][v] < INF)
                cout << d[u][v] << "\n";
            else
                cout << "no path\n";
        }
    }
}
