#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("a=b.txt", "r", stdin);
	string n, m;
	while(cin >> n >> m)
	{
		unsigned int it;
		it = n.find('.');
		if(it != -1)
		{
			int i = n.length() - 1;
			while(n[i] == '0')
			{
				n.erase(i--);
			}
			if(n[i] == '.' && i != 0)
				n.erase(i);
		}
		
		it = m.find('.');
		if(it != -1)
		{
			int i = m.length() - 1;
			while(m[i] == '0')
			{
				m.erase(i--);
			}
			if(m[i] == '.' && i != 0)
				m.erase(i);
		}
		//cout << n << endl;
		//cout << m << endl;
		if(n == m)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
