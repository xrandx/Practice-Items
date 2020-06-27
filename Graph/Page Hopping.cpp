#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 106;
const int INF = 0x3f3f3f3f;
int m[maxn][maxn];



double floyd(int& n, double& s)
{
    double sum;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                if(m[i][k] < INF && m[k][j] < INF)
                    m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
            }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i != j && m[i][j] != INF)
            {
                sum += m[i][j];
                s = s + 1;
            }
        }
    return sum / s;
}

void init(int& n, double& s)
{
    n = 0;
    s = 0;
    for(int i = 1; i <= maxn; i++)
        for(int j = 1; j <= maxn; j++)
            m[i][j] = INF;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int kase = 0;
    int a, b;
    int n = 0;
    double s = 0;
    while(scanf("%d%d", &a, &b))
    {
        init(n, s);
        if(!a && !b) break;
        m[a][b] = 1;
        n = max(max(a, b), n);
        while(scanf("%d%d", &a, &b))
        {
            if(!a && !b) break;
            m[a][b] = 1;
            n = max(max(a, b), n);
//            printf("n %d a %d b %d\n", n, a, b);
        }
        double ans = floyd(n, s);
        printf("Case %d: average length between pages = %.3lf clicks\n", ++kase, ans);
//        for(int i = 1; i <= n; i++)
//        {
//            for(int j = 1; j <= n; j++)
//            {
//                if(m[i][j] != INF) cout << m[i][j] << " ";
//                else cout << "0 ";
//            }
//            cout << "\n";
//        }

    }

    return 0;

}
