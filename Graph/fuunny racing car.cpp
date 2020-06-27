#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int n, m;
const int maxn = 306;
const int INF = 0x3f3f3f3f;

struct Node
{
    int v, a, b, t;
};
struct HeapNode
{
    int v, t;
    bool operator < (const HeapNode& rhs) const
    {
        return t > rhs.t;
    }
};

vector <int> G[maxn];
vector <Node> edges;
int done[maxn];
int Time[maxn];

void add_edge(int& u, int& v, int& a, int& b, int& t)
{
    edges.push_back(Node{v, a, b, t});
    G[u].push_back(edges.size() - 1);
}
int dijkstra(int& s, int& d)
{


}




int main()
{
//    freopen("in.txt", "r", stdin);
    int kase = 0;
    int s, d;
    int u, v, a, b, t;
    while(~scanf("%d%d%d%d", &n, &m, &s, &d))
    {
        edges.clear();
        for(int i = 0; i < n; i++)
            G[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d%d", &u, &v, &a, &b, &t);
//            cout << u << v << a << endl;
            if(a >= t) add_edge(u, v, a, b, t);
        }

    }

    return 0;
}
