#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;


const int maxn = 106;
const double INF = (1 << 30) - 1;



struct HeapNode
{
    int v; double d;
    bool operator < (const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};

struct Edge
{
    int u, v;
    double d;
};

struct Point
{
    int x, y, z, r;
};
int n;
int done[maxn];
double Time[maxn];
vector<Point> points;
vector<Edge> G[maxn];

void init()
{
    points.clear();
    for(int i = 0; i <= maxn; i++)
        G[i].clear();
}


//void pr()
//{
//    for(int i = 0; i < 3; i++)
//    {
//        printf("%d %lf\n", i, Time[i]);
//    }
//}
double dijkstra(int s, int d )
{
    priority_queue<HeapNode> q;
    memset(done, 0, sizeof(done));
    for(int i = 0; i < n; i++)
        Time[i] = INF;
    Time[s] = 0;
    q.push(HeapNode{s, 0});
    while(!q.empty())
    {
        HeapNode tmp = q.top(); q.pop();
        int& u = tmp.v;
        if(done[u]) continue;
//        if(Time[d] != INF) break;
        done[u] = 1;
        for(int i = 0; i < G[u].size(); i++)
        {
            int& v = G[u][i].v; double& d = G[u][i].d;
            if(Time[u] + d < Time[v])
            {
                Time[v] = Time[u] + d;
//                printf("v = %d  d = %lf\n", v, d);
                q.push(HeapNode{v, Time[v]});
            }
        }
    }
    return Time[d];
}

double sqr(int x) { return (double)x * x; }

void span()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                double d = sqr(points[i].x - points[j].x) + sqr(points[i].y - points[j].y) + sqr(points[i].z - points[j].z);
                d = sqrt(d);
                if(d > points[i].r + points[j].r)
                    d = d - (points[i].r + points[j].r);
                else
                    d = 0;
                d *= 10;
                G[i].push_back(Edge{i, j, d});
            }
        }
    }

//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < G[i].size(); j++)
//        {
//            cout << G[i][j].v << " " << G[i][j].d << "  " ;
//        }
//            cout << endl;
//    }
//    cout << endl;

}


int main()
{
//    freopen("in.txt", "r", stdin);
    int kase = 0, t;

    while(~scanf("%d", &t))
    {
        if(t == -1) break;
        init();
        Point tmp;
        for(int i = 0; i < t; i++)
        {
            scanf("%d%d%d%d", &tmp.x, &tmp.y, &tmp.z, &tmp.r);
            points.push_back(tmp);
        }
        n = t + 2;
        for(int i = 0; i < 2; i++)
        {
            scanf("%d%d%d", &tmp.x, &tmp.y, &tmp.z);
            tmp.r = 0;
            points.push_back(tmp);//n-1 n-2
        }
        span();
        int ans = dijkstra(n-2, n-1) + 0.5;
        printf("Cheese %d: Travel time = %d sec\n", ++kase, ans);
    }

    return 0;

}
