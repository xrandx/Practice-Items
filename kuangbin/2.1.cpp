#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include <vector>

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;

map<int, vector<int> > m;

int main()
{

	int n, m1;
	while(~scanf("%d %d", &n, &m1))
	{
		m.clear();
		int key, val;
		for(int i = 0; i < n; i++)
		{
			cin >> val;
			if(!m.count(val))
				m[val] = vector<int>();
			m[val].push_back(i + 1);
		}
		for(int i = 0; i < m1; i++)
		{
			cin >> key >> val;
			if(m.count(val) && m[val].size() >= key)
				cout << m[val][key - 1] << endl;
			else
				cout << "0" << endl;
		}
		
	}
	return 0;
}
