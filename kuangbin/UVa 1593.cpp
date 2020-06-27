#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include<sstream>
#include<cstring>
using namespace std;
const int maxn = 1006, maxm = 200;

string s[maxn][maxm];
int w[maxm], cn[maxm];

int main()
{
	memset(w, 0, sizeof(w));
	memset(cn, 0, sizeof(cn));
	string tmp;
	int c = 0, r = 0;
	while(getline(cin, tmp) && tmp[0] != '0')
	{
		stringstream ss(tmp);
		while(ss >> s[r][c] )
		{
			//cout << s[r][c] << endl;
			if(s[r][c].length() > w[c])
				w[c] = s[r][c].length();
			c++;
		}
		for(int i = 0; i < cn[1]; i++)
			cout << "w[c] "<< w[c] << "  ";
		cn[r++] = c;
		c = 0;
	}
	for(int i = 0; i < cn[2]; i++)
		cout << "w[c] "<< w[c];
	cout  << endl;
	for(int i = 0; i < r; i++)
	{
		//cout << "row"<< i ;
		for(int j = 0; j < cn[i]; j++)
		{
			//cout << "col"<<  j ;
			int sp = w[c] - s[i][j].length() + 2;
			cout << s[i][j];
			//system("pause");
			while(sp--)
				printf(" ");

		}

		cout << endl;

	}
	return 0;
}
