#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int n, m;
const int maxn = 356;
const int INF = 0x3f3f3f3f;

struct Node
{
    int v, a, b, t;
};
//struct HeapNode
//{
//    int v, t;
//    bool operator < (const HeapNode& rhs) const
//    {
//        return t > rhs.t;
//    }
//};

vector <Node> G[maxn];

int inq[maxn];
int Time[maxn];

void SPFA(int s, int d)
{
    queue< int > q;
    memset(Time, 0x3f, sizeof(Time));
    memset(inq, 0, sizeof(inq));
    q.push(s);
    inq[s] = 1;
    Time[s] = 0;
    while(!q.empty())
    {
        int now = q.front(); q.pop();
        inq[now] = 0;
        for(int i = 0; i < G[now].size(); i++ )
        {
            Node& p = G[now][i];
            int &v = p.v; int& a = p.a; int &b = p.b; int &t = p.t;
//            int t2 = (Time[now] % (a + b)) + t;
//            if(t2 > a)
//                t2 = (a + b - Time[now] % (a + b))+ t;
//            else
//                t2 = t;
//            if(Time[now] + t2 < Time[v])
//            {
//                Time[v] = Time[now] + t2;
//                q.push(HeapNode{v, Time[v]});
//            }
            int wait = a + b - Time[now] % (a + b);
            if( Time[now] % (a + b) + t <= a )
            {
                if(Time[v] > Time[now] + t)
                {
                    Time[v] = Time[now] + t;
                    //if(!done[v])
                    {
                        q.push(v);
                        inq[v] = 1;
                    }
                }
            }
            else if(Time[v] > Time[now] + t + wait)
                {
                    Time[v] = Time[now] + t + wait;
                    if(!inq[v])
                    {
                        q.push(v);
                        inq[v] = 1;
                    }
                }

        }
    }
    return;
}




int main()
{
//    freopen("in.txt", "r", stdin);
    int kase = 0;
    int s, d;
    int u, v, a, b, t;
    while(~scanf("%d%d%d%d", &n, &m, &s, &d))
    {
        for(int i = 1; i <= n; i++)
            G[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d%d", &u, &v, &a, &b, &t);
//            cout << u << v << a << endl;
            if(a >= t)
            {
                G[u].push_back(Node{v, a, b, t});
            }
        }
        SPFA(s, d);
        printf("Case %d: %d\n",++kase,Time[d]);
//        cout << G[1].size();
    }

    return 0;
}
