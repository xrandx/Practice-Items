#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>


using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 116;
int sum, de, n;
int speed[10];
int G[maxn][maxn];
int d[maxn];
int vis[maxn];

vector<int> tmp[10];

void span()
{
    for(int k = 0; k < sum; k++)
    {
        for(int i = 0; i < tmp[k].size(); i++)
        {
//            cout << tmp[k][i] << endl;
            for(int j = i + 1; j < tmp[k].size(); j++)
            {
                int& u = tmp[k][i];
                int& v = tmp[k][j];
                int w = (v - u) * speed[k];
                if(G[u][v] > w)
                {
                    G[u][v] = G[v][u] = w;
                }
            }
        }

    }
    return;
}

void dijkstra()
{
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i < 100; i++)
        d[i] = G[0][i];

    vis[0] = 1;
    d[0] = 0;
    for(int i = 0; i < 100; i++)
    {
        int flag = 1;
        int minn = INF;
        int x;
        for(int v = 0; v < 100; v++)
        {
            if(!vis[v] && d[v] < minn)
            {
                minn = d[x = v];
                flag = 0;
            }
        }
        if(flag) break;
        vis[x] = 1;
        for(int y = 0; y < 100; y++)
        {
            if(!vis[y] && G[x][y] + 60 + d[x] < d[y])
            {
                d[y] = G[x][y] + 60 + d[x];
            }
        }
    }

}

int main()
{
//    freopen("in.txt", "r", stdin);
    char s[maxn * 5];
    while(~scanf("%d%d", &sum, &de))
    {
        n = 0;
        memset(speed, 0, sizeof(speed));
        for(int i = 0; i < sum; i++)
        {
            scanf("%d", &speed[i]);
//            cout << speed[i] << " ";
        }
        getchar();
        for(int i = 0; i < sum; i++)
        {
            scanf("%[^\n]",s);
            getchar();
            tmp[i].clear();
            memset(G, 0x3f, sizeof(G));
            int j = 0;
            while(1)
            {
                int f = 0;
                while(s[j] != ' '&& j < strlen(s))
                {
                    f = f * 10 + s[j] - '0';
                    j++;
                }
//                cout << f<< endl;
                tmp[i].push_back(f);
                if(s[j] != '\0') j++;
                else break;
            }
        }
        span();
        dijkstra();
        switch(d[de])
        {
            case INF: puts("IMPOSSIBLE"); break;
            case 0: puts("0"); break;
            default: printf("%d\n", d[de]); break;

        }


    }
    return 0;
}

