#include <bits/stdc++.h>
using namespace std;
set<string> seta;
int main()
{
	//freopen("dancishu.txt", "r", stdin);
	string s;
	while(getline(cin, s) && s[0] != '#')
	{
		//getchar();
		seta.clear();
		stringstream ss(s);
		string tmp;
		while(ss >> tmp)
			seta.insert(tmp);
		cout << seta.size() << endl;

	}
	return 0;
}
