#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;

int main()
{
//    freopen("Let the Balloon Rise.txt", "r", stdin);
//    freopen("Let the Balloon Rise out.txt", "w", stdout);
	int n;
//    char str[50];
	string tmp, ans;
	int maxx = 0;
//    ~scanf("%d", &n)
	while(cin >> n)
	{
		if(n == 0) break;
		m.clear();
		maxx = 0;
		for(int i = 0; i < n; i++)
		{
//            scanf("%s", &str);
			cin >> tmp;
//            tmp.assign(str);
			if(m.find(tmp) == m.end())
				m[tmp] = 1;
			else
			{
				m[tmp]++;
			}
			if(maxx < m[tmp])
			{
				ans = tmp;
				maxx = m[tmp];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
