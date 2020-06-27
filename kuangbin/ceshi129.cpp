#include <iostream>
#include <cstdio>
#include <map>
#include <functional>
using namespace std;
map<int, int, greater<int> > m;

int main()
{
	freopen("ceshi129.txt", "r", stdin);
	int n;
	while(~scanf("%d", &n))
	{
		int a;
		for(int i = 0; i < n; i++)
		{
			cin >> a;
		}
		cout << "flag" << "\n";
//		cout << num << endl; //放在这里最后就会多输出两个
	}
}
