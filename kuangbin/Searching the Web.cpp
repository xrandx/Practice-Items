#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

vector< multimap<string, int> > dict(200);
vector< vector<string> > doc(2000);
vector<string>::iterator it;
multimap<string, int>::iterator it2;
set<int> rowset;
set<int>::iterator it3;

int main()
{
	int n;
	string s;
//	freopen("SERC.txt", "r", stdin);
	while(cin >> n)
	{
		getchar();
		dict.clear();
		doc.clear(); 
		for(int i = 0; i < n; i++)
		{
			while(getline(cin, s))
			{
				if(s[0] == '*')	break;
				int row = doc[i].size();
				doc[i].push_back(s);
				for(int j = 0; j < s.length(); j++)
					if(isalpha(s[j]))
						s[j] = tolower(s[j]);
					else s[j] = ' ';
				stringstream ss(s);
				string buf;
				while(ss >> buf)
					dict[i].insert(make_pair(buf, row));
			}
		}
		int m;
		cin >> m;
		getchar();
		string str[3];
		int flag = 0;
		for(int i = 0; i < m; i++)
		{
			str[0].clear();
			str[1].clear();
			str[2].clear();
			getline(cin, s);
			stringstream ss(s);
			string buf;
			for(int j = 0; j < 3; j++)
			{
				ss >> str[j];
//				cout << str[j] << "\n";
			}
			int _flag = 0;
			if(str[0] == "NOT")
			{
				_flag = 0;
				for(int j = 0; j < str[1].length(); j++)
					str[1][j] = tolower(str[1][j]);
				for(int j = 0; j < n; j++)
				{
					if(dict[j].find(str[1]) == dict[j].end())
					{
						if(_flag)
							cout << "----------\n";
						it = doc[j].begin();
						for(; it != doc[j].end(); it++)
							cout << *it << "\n";
						_flag = 1;
					}
				}
				if(!_flag)
					cout << "Sorry, I found nothing.\n";
			}
			else if(str[1] == "AND")
			{
				_flag = 0;
				for(int j = 0; j < str[0].length(); j++)
					str[0][j] = tolower(str[0][j]);
				for(int j = 0; j < str[1].length(); j++)
					str[2][j] = tolower(str[2][j]);
				for(int j = 0; j < n; j++)
				{
					rowset.clear();
					if(dict[j].find(str[0]) != dict[j].end() && dict[j].find(str[2]) != dict[j].end())
					{
						it2 = dict[j].begin();
						for(; it2 != dict[j].end(); it2++)
						{
							if((*it2).first == str[0] || (*it2).first == str[2])
								rowset.insert((*it2).second);
						}
						it3 = rowset.begin();
						if(_flag)
							cout << "----------\n";
						for(; it3 != rowset.end(); it3++)
						{
							cout << doc[j][*it3] << "\n";
						}
						_flag = 1;
					}
				}
				if(!_flag)
					cout << "Sorry, I found nothing.\n";

			}
			else if(str[1] == "OR")
			{
				_flag = 0;
				for(int j = 0; j < str[0].length(); j++)
					str[0][j] = tolower(str[0][j]);
				for(int j = 0; j < str[1].length(); j++)
					str[2][j] = tolower(str[2][j]);
				for(int j = 0; j < n; j++)
				{
					rowset.clear();
					if(dict[j].find(str[0]) != dict[j].end() || dict[j].find(str[2]) != dict[j].end())
					{
						it2 = dict[j].begin();
						for(; it2 != dict[j].end(); it2++)
						{
							if((*it2).first == str[0] || (*it2).first == str[2])
								rowset.insert((*it2).second);
						}
						it3 = rowset.begin();
						if(_flag)
							cout << "----------\n";
						for(; it3 != rowset.end(); it3++)
						{
							cout << doc[j][*it3] << "\n";
						}
						_flag = 1;

					}
				}
				if(!_flag)
					cout << "Sorry, I found nothing.\n";
			}
			else
			{
				for(int j = 0; j < str[0].length(); j++)
					str[0][j] = tolower(str[0][j]);
				for(int j = 0; j < n; j++)
				{
					rowset.clear();
					if(dict[j].find(str[0]) != dict[j].end())
					{
						it2 = dict[j].begin();
						for(; it2 != dict[j].end(); it2++)
						{
							if((*it2).first == str[0])
								rowset.insert((*it2).second);
						}
						it3 = rowset.begin();
						if(_flag)
							cout << "----------\n";
						for(; it3 != rowset.end(); it3++)
							cout << doc[j][*it3] << "\n";
						_flag = 1;
					}
				}
				if(!_flag)
					cout << "Sorry, I found nothing.\n";
			}
			cout << "==========\n";
		}
		return 0;
	}
}
