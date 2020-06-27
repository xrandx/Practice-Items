#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct book
{
	string t;
	int y, p;
};

int _name (const book & a, const book & b)
{
	if(a.t == b.t)
	{
		if(a.y == b.y)
			return a.p < b.p;
		else
			return a.y < b.y;
	}
	else return a.t < b.t;
}

int _year (const book & a, const book & b)
{
	if(a.y == b.y)
	{
		if(a.t == b.t)
			return a.p < b.p;
		else
			return a.t < b.t;
	}
	else return a.y < b.y;
}

int _price (const book & a, const book & b)
{
	if(a.p == b.p)
	{
		if(a.t == b.t)
			return a.y < b.y;
		else
			return a.t < b.t;
	}
	else return a.p < b.p;
}

int main()
{
	int n;
	char name[200];
	int flag = 0;
//	freopen("listbook.txt", "r", stdin);
	while(~scanf("%d", &n) && n)
	{
		book a[n];
		getchar();
		for(int i = 0; i < n ; i++)
		{
			scanf("%s", name);
			a[i].t = name;
			scanf("%d", &a[i].y);
			scanf("%d", &a[i].p);
		}
		scanf("%s", name);
		if(name[0] == 'N')
			sort(a, a+n, _name);
		else if(name[0] == 'Y')
			sort(a, a+n, _year);
		else
			sort(a, a+n, _price);
		if(flag)
			cout << "\n";
		else
			flag = 1;
		for(int i = 0; i < n ; i++)
		{
			cout << a[i].t << " ";
			cout << a[i].y << " ";
			cout << a[i].p << "\n";
		}

	}
}
