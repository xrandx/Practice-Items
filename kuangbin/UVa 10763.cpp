#include <bits/stdc++.h>
using namespace std;
map< pair<int, int> , int > m;
int main()
{
	int n;
	while(cin >> n && n)
	{
		m.clear();
		int x, y;
		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			pair<int, int> p1(x, y), p2(y, x);
			if(m[p2])
				m[p2]--;
			else
				m[p1]++;
			if(m[p2] == 0)
				m.erase(p2);
		}
		if(m.size())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;


	}
	
}

