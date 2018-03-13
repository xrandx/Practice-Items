#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;

ll n, m;


void bfs()
{
	queue<ll> q;
	ll now;
	q.push(1);
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		if(now % n == 0)
			break;
		q.push(now * 10 + 1);
		q.push(now * 10);
	}
	m = now;
	return;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	while(~scanf("%lld", &n) && n)
	{
//		printf("%lld", n);
		bfs();
		printf("%lld\n", m);
	}
	return 0;
}
