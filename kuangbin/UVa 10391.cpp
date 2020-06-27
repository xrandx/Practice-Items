#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include<cstdio>
#include<cstdlib>
using namespace std;

set<string> s;
set<string> s2;
int main()
{
	s.clear();
	s2.clear();
	string tmp, sub1, sub2;
	while(cin >> tmp )
	{
		s.insert(tmp);
	}
	set<string>::iterator it;
	for(it = s.begin(); it != s.end(); it++)
	{
		tmp = *it;
		for(int i = 1; i < tmp.length(); i++)
		{
			sub1 = tmp.substr(0, i);
			if(s.count(sub1))
			{
				sub2 = tmp.substr(i, tmp.length());
				if(s.count(sub2))
					s2.insert(tmp);
			}
		}
	}
	for(it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it <<endl;
	}
}
