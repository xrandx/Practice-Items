#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

map< int, vector<int> > m;

int main()
{
	int n, m1;
	while(scanf("%d %d", &n, &m1) != EOF)
	{
		m.clear();
		int pre, k, v;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &pre);
			if(m.find(pre) == m.end())
				m[pre] = vector<int>();
			m[pre].push_back(i + 1);
		}
		for(int i = 0; i < m1; i++)
		{
			scanf("%d %d", &k, &v);
			if(m.find(v) == m.end())
				cout << "0\n";
			else
			{
				if(m[v].size() < k)
					cout << "0\n";
				else
				{
					cout << m[v][k - 1] << endl;
				}
			}
		}
	}
	return 0;
}
