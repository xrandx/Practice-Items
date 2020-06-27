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

const int maxn = 36;
vector<int> pile[maxn];
int t;

void clear_above(int p, int h)
{
	for(int i = h + 1; i < pile[p].size(); i++)
	{
		int tmp = pile[p][i];
		pile[tmp].push_back(tmp);
	}
	pile[p].resize(h + 1);
}

void find(int a, int &p, int &h) //直接把引用当i j
{
	for(int i = 0; i < t; i++)
		for(int j = 0; j < pile[i].size(); j++)
		{
			if(pile[i][j] == a)
			{
				p = i;
				h = j;
				return;
			}
		}
}

void pile_onto(int p, int h, int p2)
{
	for(int i = h; i < pile[p].size(); i++)
		pile[p2].push_back(pile[p][i]);
	pile[p].resize(h);
}

int main()
{
	string s1, s2;
	int a, b;
	cin >> t;
	for(int i = 0; i < t; i++)
		pile[i].push_back(i);
	while(cin >> s1 && s1 != "quit" && cin>> a >> s2 >> b)
	{
		int pa, ha, pb, hb;
		find(a, pa, ha);
		find(b, pb, hb);
		if(pa == pb) continue;
		if(s1 == "move")
			clear_above(pa, ha);
		if(s2 == "onto")
			clear_above(pb, hb);
		pile_onto(pa, ha, pb);
	}
	for(int i = 0; i < t; i++)
	{
		cout << i <<":";
		for(int j = 0; j < pile[i].size(); j++)
		{
			cout << " " << pile[i][j];
		}
		cout << endl;
	}
	return 0;
}


