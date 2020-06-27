#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=300+50;
const int INF=0x3f3f3f3f;
struct Node
{
    int v,a,b,t;
};
int n,m,S,T;
vector<Node> g[maxn];
int dist[maxn],v[maxn];
void SPFA(int s)
{
    queue<int> q;
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++) dist[i]=INF;
    q.push(s), v[s]=1, dist[s]=0; 
    while(!q.empty())
    {
        int now=q.front();
        q.pop(),v[now]=0;
        for(int i=0;i<g[now].size();i++)
        {
            int nt=g[now][i].v,t=g[now][i].t;
            int a=g[now][i].a,b=g[now][i].b;
            if(dist[now]%(a+b)+t<=a)
            {
                if(dist[nt]>dist[now]+t)
                {
                    dist[nt]=dist[now]+t;
                    {
                        v[nt]=1;
                        q.push(nt);
                    }
                }
            }
            else
            {
                if(dist[nt]>dist[now]+a+b-dist[now]%(a+b)+t)
                {
                    dist[nt]=dist[now]+a+b-dist[now]%(a+b)+t;
                    if(!v[nt])
                    {
                        v[nt]=1;
                        q.push(nt);
                    }
                }
            }
        }
    }
}
int main()
{
    int cas=0;
    while(scanf("%d%d%d%d",&n,&m,&S,&T)!=EOF)
    {
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v,a,b,t;
            scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
            if(a>=t) g[u].push_back((Node){v,a,b,t});
        }
        SPFA(S);
        printf("Case %d: %d\n",++cas,dist[T]);
    }
    return 0;
}
