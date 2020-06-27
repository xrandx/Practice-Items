#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
typedef map<string, map<string, int > > P;
typedef map<string, int> P2;
map<string, map<string, int > >::iterator it;
map<string, int>::iterator it2;
P loc;

int main()
{
	int t, n;
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while(t--)
	{
		loc.clear();
		scanf("%d", &n);
		getchar();
		int i = n, num;
		string s1, s2;
		s1.resize(100);
		s2.resize(100);
		while(i--)
		{
//			scanf("%s", &s2[0]);
//			scanf("%s%d", &s1[0], &num);;
//			cin >> s2 >> s1 >> num;
			if(loc.count(s1))
			{
				if(loc[s1][s2])
					loc[s1][s2] += num;
				else
					loc[s1][s2] = num;
			}
			else
				loc[s1][s2] = num;
		}
		for(it = loc.begin(); it != loc.end(); it++)
		{
			cout << (*it).first << endl;
			for(it2 = (*it).second.begin(); it2 != (*it).second.end(); it2++)
			{
				cout << "   |----";
				cout << (*it2).first << "("<<(*it2).second << ")" << endl;
			}
		}
		if(t)
			cout << endl;
	}
}

//guangdong
//   |----pineapple(5)
//   |----sugarcane(1)
//shandong
//   |----apple(3)


/*
class fnode
{
	public:
		map<string, int> fru;

		fnode(const string & s, const int & num)
		{
			if(fru[s])
				fru[s] += num;
			else
				fru[s] = num;
		}
		bool operator = (pair<string, int> & a)
		{
			if(fru[a.first])
				fru[a.first] += a.second;
			else
				fru[a.first] = a.second;
		}

		bool operator < (const fnode & a)
		{

		}
};*/
