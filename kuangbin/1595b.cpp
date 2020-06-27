#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<set>
#include<string>
#include <stack>
#define INF 1000000005
#define LL long long
const LL MOD = 100000000000000003;
#define MAXN 1000+10
using namespace std;

struct po{
    double x, y;
    po(int a = 0, int b = 0):x(a), y(b){}
    bool friend operator < (po a, po b){
        if(a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    }
};

int main (){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        po s[MAXN];
        double l = INF, r = -INF;
        set <po> q;
        for(int i = 0; i < n; i++){
            scanf("%lf%lf",&s[i].x, &s[i].y);
            l = min(l, s[i].x);
            r = max(r, s[i].x);
            q.insert(s[i]);
        }
        double mid = (l+r)/2.0;
        int flag = 0;
        for(int i = 0; i < n; i++){
            if(!q.count(po(-s[i].x + 2*mid, s[i].y))){
                flag = 1;
                printf("NO\n");
                break;
            }
        }
        if(!flag)
            printf("YES\n");
    }
    return 0;
}
