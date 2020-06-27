#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> P;
map < P, int > m;
map <int, string> mtitle;
map <string, int> mid;
set <int> all;
set <int> ret;

bool operator < (P & p1, P & p2	)
{
	if(p1.second != p2.second)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

int main()
{
	string s, title, author;
	//freopen("Borrowers.txt", "r", stdin);
	while(getline(cin, s) && s[0] != 'E')
	{
		int pos2 = 0, pos3 = 0, pos4;
		for(int i = 1; i < s.length(); i++)
		{
			if(pos2 == 0 && s[i] == '"')
				pos2 = i;
			if(pos2 && s[i] == 'b' && s[i+1] == 'y')
				pos3 = i + 3;
			if(pos3 && s[i] == '.' && s[i+1] != ' ')
			{
				pos4 = i;
				break;
			}
		}
		title = s.substr(1, pos2 - 1);
		author = s.substr(pos3, pos4 - pos3 + 1);
		P couple(title, author);
		m.insert(make_pair(couple, 0));
	}
	int j = 0;
	for(map<P, int>::iterator it = m.begin() ; it != m.end(); it++, j++)
	{
		mid[(*it).first.first] = j;
		mtitle[j] = (*it).first.first;
		all.insert(j);
//		cout << (*it).first.first << " " << (*it).first.second << endl;
	}
	while(getline(cin, s))
	{
		if(s[0] == 'E') break;
		if(s[0] == 'S')
		{
			set<int>::iterator it =  ret.end();
			it--; 
			int flag = 0;
			for( ; ; it--)
			{
				if(it == ret.begin())
					flag = 1;
				if(all.size() == 0)
					cout << "Put " << mtitle[0] << " first" << endl;
				else
				{
					int id = *(all.lower_bound(*it));
					if(id == (*it))
						continue;
					cout << "Put \"" << mtitle[*it] << "\" after "<< mtitle[--id] << "\"" << endl;
					all.insert((*it));
				}
				if(flag) break;
			}
		}
		else
		{
			string t = s.substr(8, s.length() - 9);
			//cout << s[0] << t << endl;
			if(s[0] == 'B')
				all.erase(mid[t]);
			else
				ret.insert(mid[t]);
			
		}
		s.clear();
	}
	cout << "END" << endl;
}


