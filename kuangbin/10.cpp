#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

#include<cstdio>
#include<cstdlib>

using namespace std;

const int maxt = 1006;

int main()
{
	int t;
	int kase = 1;
	while(~scanf("%d", &t) && t)
	{
		map<int, int> team;
		queue<int> q, q2[maxt];
		cout << "Scenario #" << kase++ << endl;
		for(int i = 0; i < t; i++)
		{
			int n;
			cin >> n;
			while(n--)
			{
				int x;
				cin >> x;
				team[x] = i;
			}
		}
		while(1)
		{
			string s;
			//char cmd[10];
			int x;
			cin >> s;
			if(s[0] =='E')
			{
				cin >> x;
				int num = team[x];
				if(q2[num].empty())
					q.push(num);
				q2[num].push(x);
			}
			else if(s[0] == 'D')
			{

				if(!q.empty())
				{
					int num = q.front();
					int x;
					x = q2[num].front();
					q2[num].pop();
					if(q2[num].empty())
						q.pop();
					cout << x << endl;
				}
			}
			else if(s[0] == 'S')
			{
				cout << endl;
				break;
			}
		}
	}
	return 0;
}
