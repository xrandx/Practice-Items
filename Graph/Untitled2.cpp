#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxm = 5000 + 5 ;
int n,m,u[maxm],v[maxm],w[maxm];
int r[maxm],p[maxm];
int cmp(int i,int j) {return w[i]<w[j];}
int find(int x) {return p[x]==x?x:p[x]=find(p[x]);}
void Solve()
{
    while(cin>>n>>m){
        if (n==0&&m==0) break;
        for(int i=0;i<m;i++){
            cin>>u[i]>>v[i]>>w[i];
            u[i]--,v[i]--,w[i]--;
        }
        for(int i=0;i<m;i++)
            r[i]=i;
        sort(r,r+m,cmp);
        int ans=INF;
        for(int L=0;L<m;L++){
            for(int i=0;i<n;i++)
                p[i]=i;
            int cnt=0,R;
            for(R=0;L+R<m;R++){
                int e=R+L;
                int x=find(u[r[e]]),y=find(v[r[e]]);
                if (x!=y){
                    cnt++;
                    p[x]=y;
                }
                if (cnt==n-1)
                    break;
            }
            if(cnt==n-1)
                ans=min(ans,w[r[R+L]]-w[r[L]]);
        }
        if (ans!=INF) printf("%d\n",ans);
        else puts("-1");
    }
}
int main()
{
    Solve();
    return 0;
}
