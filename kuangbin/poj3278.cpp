#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int maxn = 100005;
bool visited[maxn];
int time[maxn];
queue < int > q;

int bfs(int n, int k)
{
	int now;
	int next;
	q.push(n);
	time[n] = 0;
	visited[n] = true;
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		for(int i=0; i<3; i++)
		{
			if(i == 0)
			{
				next = now - 1;
			}
			else if(i == 1)
			{
				next = now + 1;
			}
			else if(i == 2)
			{
				next = 2*now;
			}
			if(next > maxn || next < 1)	continue;

			if(!visited[next])
			{
				q.push(next);
				visited[next] = true;
				time[next] = time[now] + 1;
			}
			if( next == k )
			{
				return time[next];
			}
		}
	}
}

int main()
{
	memset(visited, false, sizeof(visited));
	int n,k;
	while(cin >> n >> k)
	{
		if(n >= k)
		{
			cout << n - k << endl;
			continue;
		}
		else
		{
			cout << bfs(n, k) << endl;
		}
	}
	return 0;
}
