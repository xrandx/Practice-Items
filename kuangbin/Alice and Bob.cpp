#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100006;

struct card
{
    int h, w;
    bool operator < (const card &c) const
    {
        return h < c.h;
    }
};

inline void foo(card a[], int n)
{
    for(int i = 0; i < n; i++)
//        cin >> a[i].h >> a[i].w;
        scanf("%d%d", &a[i].h, &a[i].w);
}

card a[maxn];
card b[maxn];
multiset<int> mset;
int ans = 0, n, j, t;
multiset<int>::iterator it;

int main()
{
//    cin >> t;
    scanf("%d", &t);
    while(t--)
    {
//        cin >> n;
        scanf("%d", &n);
        foo(a, n);
        foo(b, n);
        sort(a, a+n);
        sort(b, b+n);
        mset.clear();
        j = 0;
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            while(j < n && b[j].h <= a[i].h)
                mset.insert(b[j++].w);
            if(mset.empty()) 
                continue;
            it = mset.lower_bound(a[i].w);
            if(it == mset.end() || (*it > a[i].w && it != mset.begin()) ) 
                it--;
            if(*it <= a[i].w)
            {
                ans++;
                mset.erase(it);
            }
        }
//        cout << ans << endl;
        printf("%d\n", ans);
    }
    return 0; 
}
