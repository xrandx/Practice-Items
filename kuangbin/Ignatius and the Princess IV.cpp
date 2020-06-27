#include <iostream>
#include <cstdio>
#include <map>
#include <functional>
using namespace std;
map<int, int, greater<int> > m;

int main()
{
//	freopen("in.txt", "r", stdin);
	int n;
	while(~scanf("%d", &n))
	{
		m.clear();
		int mini = (n + 1) / 2;
		int num[n], maxn;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}
		for(int i = 0; i < n; i++)
		{
			if(m.count(num[i]))
			{
				m[num[i]]++;
				if(m[num[i]] >= mini)
				{
					maxn = num[i];
					break;
				}
			}
			else
				m[num[i]] = 1;
		}
		cout << maxn << "\n";
//		cout << num << endl; //放在这里最后就会多输出两个
	}
}
