#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 206;
const double INF = 1e8;
const double eps = 1.0e-8;
int n;
int x[maxn], y[maxn];

struct node
{
	int v;
	double d;
	bool operator < (const node& rhs) const
	{
		return d - rhs.d > eps;
	}
	node (int v = 0, double d = 0.0): v(v), d(d){
	};
};

vector<node> edges;
vector<int> G[maxn];
int vis[maxn];
double d[maxn];


inline double sq(int x)
{
	return (double)(x * x);
}


void add_edges()
{
	int m = 0;
	for(int i = 1; i <= n; i++)
		G[i].clear();
	edges.clear();
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			double d = sq(x[i] - x[j]) + sq(y[i] - y[j]);
			d = sqrt(d);
			edges.push_back(node(j, d));
			G[i].push_back(m++);
			edges.push_back(node(i, d));
			G[j].push_back(m++);
		}
	}
}

void dijkstra()
{
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i <= n; i++)
		d[i] = INF;
	d[1] = 0;
	priority_queue<node> q;
	q.push(node(1,0.0));
	while(!q.empty())
	{
		node now = q.top();
		q.pop();
		int& u = now.v;
		if(u == 2) break;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < G[u].size(); i++)
		{
			int& v = edges[G[u][i]].v;
			double& dist = edges[G[u][i]].d;
			if(d[v] - max(d[u], dist) > eps)
			{
				d[v] = max(d[u], dist);
				q.push(node(v, d[v]));
			}
		}
	}

}

int main()
{
//	freopen("in.txt", "r", stdin);
	int kase = 0;
	while(~scanf("%d", &n) && n)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
//			printf("%d", x[i]);
		}
		add_edges();
		dijkstra();
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++kase, d[2]);
		
	}
	return 0;
}
