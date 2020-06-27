#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string, string> oldd, neww;
map<string, string>::iterator it, it2;

int main()
{
//	freopen("diction.txt", "r", stdin);
	int n;
	string s1, s2, str;
	char s[1000];
	int val;
	while(~scanf("%d ", &n))
	{
		int flag1 = 1, flag = 0, last = 0;
		for(int i = 0; i < n; i++)
		{
			oldd.clear();
			neww.clear();
			getchar();
//			cout << "_____\n";
			while(1)
			{
				scanf("%[^:]", s);
				getchar();//:
				scanf("%d", &val);
				oldd[s] = val;
//				cout << s << " " << val << "\n";
				if(getchar() =='}')
					break;
				//,
			}
			getchar();getchar();
//			cout << "_____\n";
			while(1)
			{
				scanf("%[^:]", s);
				getchar();//:
				scanf("%d", &val);
				neww[s] = val;
//				cout << s << " " << val << "\n";
				if(getchar() =='}')
					break;
				//,
			}
			getchar();//\n
			
			it = neww.begin();
			flag1 = 1;
			flag = 0;
			if(last)
				cout << "\n\n";
			for(; it != neww.end(); it++)
			{
				if(oldd.find((*it).first) == oldd.end())
				{
					if(flag1)
					{
						cout << "+" << (*it).first;
						flag1 = 0;
						last = 1;
					}
					else
						cout << "," << (*it).first ;
				}
			}
			flag += flag1;
			it = oldd.begin();
			flag1 = 1;
			for(; it != oldd.end(); it++)
			{
				if(neww.find((*it).first) == neww.end())
				{
			//					cout << "y";
					if(flag1)
					{
						if(flag == 0) cout << "\n";
						cout << "-" << (*it).first;
						flag1 = 0;
						last = 1;
					}
					else
						cout << "," << (*it).first ;
				}
			}
			flag += flag1;
			it = neww.begin();
			flag1 = 1;
			for(; it != neww.end(); it++)
			{
				if(oldd.find((*it).first) != oldd.end())
				{
					if((*it).second != oldd[(*it).first])
					{
						if(flag1)
						{
							if(flag <= 1) cout << "\n";
							cout << "*" << (*it).first;
							flag1 = 0;
							last = 1;
						}
						else
							cout << "," << (*it).first ;
					}
				}
			}
			flag += flag1;
			if(flag == 3)
				cout << "No changes";
			
		}
	}
}





//3
//{a:3,b:4,c:10,f:6}
//{a:3,c:5,d:10,ee:4}
//{x:1,xyz:123456789123456789123456789}
//{xyz:123456789123456789123456789,x:1}
//{first:1,second:2,third:3}
//{third:3,second:2}
