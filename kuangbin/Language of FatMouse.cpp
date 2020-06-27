#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

map<string, string> m;

int main()
{
	char str[30];
	char str1[12];
	char str2[12];
//	freopen("fat.txt", "r", stdin);
	m.clear();
	while(gets(str))
	{
		if(strcmp(str,"") == 0)
			break;
		int i, l = strlen(str);
		for(i = 0; i < l; i++ )
		{
			if(str[i] == ' ')
				break;
		}
		strncpy(str1, str, i);
		str1[i + 1] = '\0';
//		cout << str1 << "\n";
		strncpy(str2, str + i + 1, l - i);
//		cout << str2 << "\n";
		str2[l - i + 1] = '\0';
		m[str2] = str1;
	}
	
//string s(str1);

	string s;
	while(cin >> s)
	{
		if(m.count(s)) 
		{
			cout << m[s]<< "\n";
//			cout << m[s] << "\n";
		}
		else
		{
//			printf("eh\n");
			cout << "eh\n";
		}
	}
	return 0;
}
