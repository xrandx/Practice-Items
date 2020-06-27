struct Edge
{
    int  from, to, time, a, b;
    Edge(int u, int v, int t, int a, int b): from(u), to(v), time(t), a(a), b(b){}
};

struct HeapNode
{
    int d, u;
    bool operator < (const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};




int n, m;
vector<Edge> edges;
vector<int> G[maxn];
bool done[maxn];
int d[maxn];
int p[maxn];

void init(int n)
{
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edge.clear();
}

void AddEdge(int from, int to, int dist)
{
    edges.push_back(Edge(from, to, dist));
    m = edges.size();
    G[from].push_back(m - 1);
}

void dijkstra(int s)
{
    priority_queue<HeapNode> Q;
    for(int i = 0; i < n; i++) d[i] = INF;
    memset(done, 0, sizeof(done));
    d[s] = 0;
    int wait = 0;
    Q.push((HeapNode){0, s});
    while(!Q.empty())
    {
        HeapNode u = Q.top(); Q.pop();
        int x = u.u;
        if(done[x]) continue;
        d[x] = true;
        for(int i = 0; i < G[x].size(); i++)
        {
            Edge& e = edges[G[x][i]];
            if(d[e.to] > d[x] + e.time)
            {
                d[e.to] = d[x] + e.time;
                p[e.to] = x;
                Q.push((HeapNode){d[e.to], e.to});
            }
        }
    }
}


