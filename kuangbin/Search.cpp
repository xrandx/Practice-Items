#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

struct index
{
	int doc, row;
};


vector< map<string, index> > dict(200);

vector<string>::iterator it;


int main()
{
	int n;
	string s;
	while(cin >> n)
	{
		dict.clear();
		vector< vector<string> > doc(n + 1);
		for(int i = 0; i < n; i++)
		{
			while(getline(cin, s))
			{
				if(s[0] == '*')	break;
				index _index;
				_index.doc = i;
				_index.row = doc[i].size();
				doc[i].push_back(s);
				for(int j = 0; j < s.length(); j++)
					if(isalpha(s[j]))
						s[j] = tolower(s[j]);
					else s[j] = ' ';
				stringstream ss(s);
				string buf;
				while(ss >> buf)
					dict[i][buf] = _index;
			}
		}
		int m;
		cin >> m;
		string str[6];
		for(int i = 0; i < m; i++)
		{
			str[0].clear();
			str[1].clear();
			str[2].clear();
			getline(cin, s);
			stringstream ss(s);
			string buf;
			for(int j = 0; j < 3; j++)
				ss >> str[j];
			int _flag = 0;
			if(str[0] == "NOT")
			{
				_flag = 0;
				for(int j = 0; j < n; j++)
				{
					if(dict[j].find(str[1]) == dict[j].end())
					{
						it = doc[j].begin();
						for(; it != doc[j].end(); it++)
							cout << *it << "\n";
						if(_flag) cout << "---------\n";
						_flag = 1;
					}
					else
					{
						_flag = 0;
					}

				}
			}
			else if(str[1] == "AND")
			{
				for(int j = 0; j < n; j++)
				{
					_flag = 0;
//					if(dict)
				}

			}

		}
	}
	return 0;
}
