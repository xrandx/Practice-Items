#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 100006;

int vis[maxn];
int n, k;

void bfs()
{
	queue<int> q;
	int now, tmp, r;
	q.push(n);
	while(!q.empty())
	{
		now = q.front(); 
		q.pop();
		if(now == k) return;
		r = vis[now] + 1;
		tmp = now - 1;
		if(tmp >= 0 && !vis[tmp])
		{
			q.push(tmp);
			vis[tmp] = r;
		}
		tmp = now + 1;
		if(tmp <= k && !vis[tmp] )
		{
			q.push(tmp);
			vis[tmp] = r;
		}
		tmp = now * 2;
		if( tmp < maxn && !vis[tmp])
		{
			q.push(tmp);
			vis[tmp] = r;
		}
	}
}

int main()
{
//	freopen("in.txt", "r", stdin);
	while(scanf("%d%d", &n, &k) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		bfs();
		printf("%d\n", vis[k]);
	}
	return 0;
}
