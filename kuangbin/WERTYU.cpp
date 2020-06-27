#include <iostream>
#include <string>
#include <map>
using namespace std;
string str = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
map<char, char> dict;

int main()
{
	for(int i = 1; i < str.length(); i++)
		dict[str[i]] = str[i - 1];
	string s;
	while(getline(cin, s))
	{
		for(int i = 0; i < s.length(); i++)
		{
			if(dict.find(s[i]) != dict.end())
				cout << dict[s[i]];
			else if(s[i] == ' ')
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
