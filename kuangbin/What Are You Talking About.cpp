#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;
map<string, string> m;
int main()
{
//	freopen("What Are You Talking About.txt", "r", stdin);
//    freopen("What Are You Talking About out.txt", "w", stdout);
	char  str[500000];
	char cmd[50000], eng[50000], mar[50000];
	while(1)
	{
		if(scanf("%[A-Z]", cmd) == 1)
			getchar();
		if(cmd[0] == 'S')
		{
			scanf("%[^ ]", eng);
			scanf(" %[^\n]", mar);
			getchar();
			m[mar] = eng;
//			cout << eng << " " << mar << "\n";
		}
		else
			break;
	}
	string s, a, b;
//	cin>>s;
//	while(cin >> a && a != "END")
//	{
//		cin>>b;
//		m[b] = a;
//	}
	cin>>s;//cout<<s<<endl;
	getchar();
	string s1 = "";
	while(getline(cin,s) && s != "END")
	{

			for(int i = 0; i < s.length(); i++)
			{
				if(islower(s[i]))
				{
					s1 += s[i];
				}
				else
				{
					if(m.find(s1) != m.end())
						cout << m[s1];
					else
						cout << s1 ;
					s1 = "";
					cout << s[i];
				}
			}
			cout << "\n";
	}

	return 0;
}


//					if(i == strlen(str) - 1)
//					{
//						if(m.find(s1) != m.end())
//							cout << m[s1];
//						else
//							cout << s1;
//						s1 = "";
//					}

//START
//from fiwo
//hello difh
//mars riwosf
//earth fnnvk
//like fiiwj
//END
//START
//difh, i'm fiwo riwosf.
//i fiiwj fnnvk!
//END
