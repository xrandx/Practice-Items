#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 106;
const int maxcol = 60;

string fname[maxn];


inline void print(const string &s, const int &len, const string &ex)
{
	cout << s;
	for(int i = 0; i < len - s.length(); i++)
		cout << ex;
}

int main()
{
	int n;
	while(cin >> n)
	{
		int maxl = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> fname[i];
			maxl = max( maxl, (int)fname[i].length());
		}
		sort(fname, fname + n);
		int col = (maxcol - maxl) / (maxl + 2) + 1;
		int row = (n - 1) / col + 1;//非常巧妙应对两种情况
		print("", maxcol, "-");
		cout << "\n";
		for(int i = 0; i < row; i++)
		{
			int j;
			int idx;
			for(j = 0; j < col - 1; j++)
			{
				idx = i + j * row;
				if(idx < n)
					print(fname[idx], maxl + 2, " ");
			}
			idx = i + j * row;
			if(idx < n)
				print(fname[idx], maxl, " ");
			cout << "\n";
		}

	}
	return 0;
}
