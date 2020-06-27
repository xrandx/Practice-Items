#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include <vector>

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>


using namespace std;

int main()
{

	int n, m;
	while(~scanf("%d %d", &n, &m))
	{
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < m; i++)
		{
			int k, v;
			int loc = 0, cnt = 0;
			cin >> k >> v;
			for(int j = 0; j < n; j++)
			{
				if(a[j] == v)
				{
					cnt++;
					if(cnt == k)
					{
						loc = j;
						break;
					}
				}
			}
			cout << (loc == 0 ? 0: loc + 1) << endl;
		}
		return 0;
	}
}
