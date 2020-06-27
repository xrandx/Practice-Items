#include <bits/stdc++.h>
using namespace std;
set<int> seta;
int main()
{
	//freopen("abset.txt", "r", stdin);
	int n, m;
	while(cin >>  n >> m)
	{
		int tmp;
		seta.clear();
		for(int i = 0 ; i < n; i++)
		{
			cin >> tmp;
			seta.insert(tmp);
		}
		for(int i = 0 ; i < m; i++)
		{
			cin >> tmp;
			seta.insert(tmp);
		}
		set<int>::iterator it = seta.begin();
		cout << *it;
		it++;
		for(; it != seta.end(); it++)
		{
			cout << " " << *it;
		}
		cout << endl;
	}
}
