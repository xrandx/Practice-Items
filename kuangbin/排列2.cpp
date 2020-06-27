#include <bits/stdc++.h>
using namespace std;

set<int> seta;
int main()
{
	int a[4];
	int flag = 0;
	freopen("pailie.txt", "r", stdin);
	while(cin >> a[0] >> a[1] >> a[2] >> a[3] && (a[0]  || a[1] || a[2] || a[3]))
	{
		seta.clear();
		if(flag++)
			cout << endl;
		int num;
		int b[4];
		if(a[0] == a[1] && a[2] == a[3] && a[3] == a[1])
		{
			num =  a[0] * 1000  + a[1] * 100 + a[2] * 10 + a[3];
			cout << num << endl;
		}
		else
		{
			int cnt = 24;
			while(cnt--)
			{
				/*
				if(next_permutation(a, a+4))
				{
					num =  a[0] * 1000  + a[1] * 100 + a[2] * 10 + a[3];
					seta.insert(num);
				}
				else
				{
					next_permutation(a, a+4);
					num =  a[0] * 1000  + a[1] * 100 + a[2] * 10 + a[3];
					seta.insert(num);
					break;
				}*/
				next_permutation(a, a+4);
				num =  a[0] * 1000  + a[1] * 100 + a[2] * 10 + a[3];
				if(num > 999)
					seta.insert(num);
			}
			set<int>::iterator it2 = seta.begin();
			it2++;
			//cout << endl;
			for(set<int>::iterator it = seta.begin(); it != seta.end(); it++, it2++)
			{
				int f1, f2;
				f1 = *it / 1000;
				f2 = *it2 / 1000;
				if(f1 == f2)
				{
					cout << *it << " ";
				}
				else //if(it2 == seta.end())
				{
					cout << *it << endl;
				}

			}
		}
		
		

	}

}
