#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int first[100005],cnt;

struct point{
    int v,next,w;
}edge[200005];

void add(int x,int y,int z)
{
    edge[cnt].next=first[x];
    edge[cnt].v=y;
    edge[cnt].w=z;
    first[x]=cnt++;
}


int main()
{
    int sum,res,msum,i,j,t,n,x,y,z,cas=1;
//    freopen("in.txt", "r", stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<=n;i++) first[i]=-1;
        for(sum=cnt=i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            sum=sum+z;
            add(x,y,z);
            add(y,x,z);
        }
        for(res=0,i=1;i<=n;i++)
        {
            cnt=msum=0;
            int maxw = -1;
            for(j=first[i];j!=-1;j=edge[j].next)
            {
                maxw = max(maxw, edge[j].w);
                msum+=edge[j].w;
            }
            if(2*maxw>=msum) res+=maxw;
            else res+=(msum+1)/2;
        }
        printf("Case #%d: %d\n",cas++,res-sum);
    }

    return 0;
}
