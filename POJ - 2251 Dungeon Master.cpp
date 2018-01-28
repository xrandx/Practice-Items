#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 36;
int l,r,c, ans;
int m[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];

struct loc
{
	int l,r,c,t;
	loc(int l = 1, int r = 1, int c = 1, int t = 0): l(l), r(r), c(c), t(t){	};
	bool operator == (const loc& rhs) const
	{
		return (l == rhs.l && r == rhs.r && c == rhs.c);
	}
	loc operator += (const loc& rhs)
	{
		l += rhs.l;
		r += rhs.r;
		c += rhs.c;
		t++;
		return (loc){l, r, c, t};
	}
};

loc mov[6] =  {(loc){0, -1, 0}, (loc){0, 1, 0}, (loc){1, 0, 0}, (loc){-1, 0, 0}, (loc){0, 0, -1}, (loc){0, 0, 1}};

inline bool legal(loc& tmp)
{
	if(tmp.l >= 1 && tmp.l <= l && tmp.r >= 1 && tmp.r <= r && tmp.c >= 1 && tmp.c <= c)
	{
		if(m[tmp.l][tmp.r][tmp.c])
			return true;
	}
	return false;
}

int bfs(loc s, loc e)
{
	loc now;
	queue<loc> q;
	vis[s.l][s.r][s.c] = 1;
	q.push(s);
	while(!q.empty())
	{
		now = q.front(); q.pop();
//		printf("\n%d %d %d now\n", now.l, now.r, now.c);
		if(now == e)
		{
			ans = now.t;
			return 1;
		}
		for(int i = 0; i < 6; i++)
		{
			loc tmp = now;
			tmp += mov[i];
//			printf("\n%d %d %d %d tmp\n", tmp.l, tmp.r, tmp.c, tmp.t);
			if(legal(tmp) && !vis[tmp.l][tmp.r][tmp.c])
			{
				q.push(tmp);
				vis[tmp.l][tmp.r][tmp.c] = 1;
//				m[tmp.l][tmp.r][tmp.c] = min(m[now.l][now.r][now.c] + 1, m[tmp.l][tmp.r][tmp.c]);
			}
		}
	}
	return 0;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	while(scanf("%d%d%d", &l, &r, &c) != EOF && l)
	{
		memset(m, 0, sizeof(m));
		memset(vis, 0, sizeof(vis));
		ans = 0;
		loc s, e;
		getchar();
		for(int i = 1; i <= l; i++)
		{
			for(int j = 1; j <= r; j++)
			{
				for(int k = 1; k <= c; k++)
				{
					char ch = getchar();
					if(ch == '.')
						m[i][j][k] = 1;
					else if(ch == 'S')
					{
						s.l = i;
						s.r = j;
						s.c = k;
						m[i][j][k] = 1;
					}
					else if(ch == 'E')
					{
						e.l = i;
						e.r = j;
						e.c = k;
						m[i][j][k] = 1;
					}
//					printf("%c", ch);
				}
				getchar();
//				cout << endl;
			}
			getchar();
		}
		if(bfs(s, e))
		{
			printf("Escaped in %d minute(s).\n", ans);
		}
		else printf("Trapped!\n");
	}
}
