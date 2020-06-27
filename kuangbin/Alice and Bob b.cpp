#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <queue>

using namespace std;
const int maxn=1e5+5;
struct T
{
	int h;
	int w;
	bool operator < (const T & a) const
	{
		return h<a.h;
	}
};
void read(T * a,int n)
{
	for(int i=0; i<n; i++)
		scanf("%d%d",&a[i].h,&a[i].w);
}
T a[maxn];
T b[maxn];
int ans;
int n;
multiset<int> st;
multiset<int>::iterator p;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		read(a,n);
		read(b,n);
		sort(a,a+n);
		sort(b,b+n);
		st.clear();
		ans=0;
		int j=0;
		for(int i=0; i<n; i++)
		{
			while(j<n&&b[j].h<=a[i].h)
				st.insert(b[j++].w);
			if(st.empty()) continue;
			p=st.lower_bound(a[i].w);
			if(p==st.end()||*p>a[i].w&&p!=st.begin()) p--;
			if(*p<=a[i].w)
			{
				ans++;
				st.erase(p);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
