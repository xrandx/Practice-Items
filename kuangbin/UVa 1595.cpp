#include <bits/stdc++.h>
using namespace std;
const int maxn = 1006;
typedef pair<int, int>  P;


bool operator < (P & p1, P & p2)
{
	if(p1.first != p2.first)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main()
{
	//freopen("UVa 1595si.txt", "r", stdin);
	int n;
	set<P> seta;
	cin >> n;
	while(n--)
	{
		seta.clear();
		int m;
		int x, y;
		scanf("%d", &m);
		int minx = 1000000, maxx = -1000000;
		P v[m];
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			x *= 2;
			P tmp(x, y);
			seta.insert(tmp);
			v[i] = tmp;
			minx = min(minx, x);
			maxx = max(maxx, x);
		}
		int mid = (minx + maxx) / 2;
		int flag = 1;
		for(int i = 0; i < m; i++)
		{
			if(!seta.count(make_pair(mid * 2 - v[i].first, v[i].second)))
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
