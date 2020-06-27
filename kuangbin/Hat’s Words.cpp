#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <functional>
using namespace std;

set<string> seta, setb;
set<string>::iterator it;
int main()
{
//		freopen("in.txt", "r", stdin);
	string s;
	while(getline(cin, s))
	{
		seta.insert(s);
	}
	for(it = seta.begin(); it != seta.end(); it++)
	{
		string tmp;
		tmp = *it;
		for(int i = 1; i < tmp.length(); i++)
		{
			string sub = tmp.substr(0, i);
			if(seta.count(sub))
			{
				sub = tmp.substr(i, tmp.length());
				if(seta.count(sub))
				{
					setb.insert(tmp);
					break;
				}
			}
		}
	}
	for(it = setb.begin(); it != setb.end(); it++)
	{
		cout << *it <<endl;
	}
	return 0;
}
