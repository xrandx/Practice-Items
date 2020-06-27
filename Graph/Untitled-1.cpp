#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    int v[maxn];
    int d[maxn];
    const int INF = 0x3f3f3f3f;
    memset(v, 0, sizeof(v));
    d[0] = 0;
    for(int i = 1; i < n; i++) d[i] = INF;
    for(int i = 0; i < n; i++) 
    {
        int x, m = INF;
        for(int y = 0; y < n; y++)
            if(!v[y] && d[y] <= m) m = d[x=y];
        v[x] = 1;
        for(int y = 0; y < n; y++)
            d[y] = min(d[y], d[x] + w[x][y]);
        
    }
}
