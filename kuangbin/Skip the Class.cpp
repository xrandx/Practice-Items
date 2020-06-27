#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef struct node
{
	string lesson;
	int val;
	bool operator < (const node & b)
	{
		if(lesson != b.lesson)
			return lesson < b.lesson;
		return val > b.val;
	}
}_node;

_node v[106];
int main()
{
//	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		_node a;
		for(int i = 0; i < n; i++)
		{
			cin >> a.lesson >> a.val;
			v[i] = a;
		}
		sort(v, v+n);
		int maxx = 0, flag;
		string s = "*";
		for(int i = 0; i < n; i++)
		{
			if(v[i].lesson != s)
			{
				maxx += v[i].val;
				s = v[i].lesson;
				flag = 1;
			}
			else if(flag)
			{
				maxx += v[i].val;
				flag--;
			}
//			cout << v[i].lesson << v[i].val <<endl;
		}
		cout << maxx << endl;
	}
}
