#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s, one;
	while(cin >> s && s[0] != '#')
	{
		cin >> one;
		int pos, len = one.length();
		int cnt = 0;
		while(1)
		{
			pos = s.find(one);
			if(pos == -1) break;
			else
				cnt++;
			s.erase(0, pos + len);
		}
		cout << cnt << endl;
	}
}
