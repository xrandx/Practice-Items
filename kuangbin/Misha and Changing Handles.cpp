#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<string, string> xtoy;
map<string, string> ytox;

map<string, string>::iterator it;
map<string, string>::iterator it2;

int main()
{
	int q;
	while(cin >> q)
	{
		xtoy.clear();
		ytox.clear();
		string s1, s2;
		int id;
		for(int i = 0; i < q; i++)
		{
			cin >> s1 >> s2;
			if(ytox.find(s1) != ytox.end())
			{
				xtoy[ytox[s1]] = s2;
				ytox[s2] = ytox[s1];
			}
			else
			{
				xtoy[s1] = s2;
				ytox[s2] = s1;
			}

		}
		cout << xtoy.size() <<endl;
		for(it = xtoy.begin(); it != xtoy.end(); it++)
		{
			cout << (*it).first << " " << (*it).second << endl;
		}

	}

	return 0;
}
