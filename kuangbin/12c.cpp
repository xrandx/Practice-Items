#include<iostream>
#include<map>
#include<string>
#include<cstdio>

using namespace std;
const int maxn=10000+5;
string s[maxn][15];//´æ×Ö·û´®
map<string ,int>str_id;//½«×Ö·û´®×ªÎªid
typedef pair<int,int>p;
int n,m;

int main()
{
//    ios::sync_with_stdio(false);

    while(cin>>n>>m)
    {
       str_id.clear();
        getchar();
        //read
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                s[i][j]="";
                while(1)
                {
                    char c=getchar();
                    if(c==','||c=='\n')break;
                     s[i][j]+=c;
                }
                str_id[s[i][j]]=j*100000+i;//id
            }
        }
        //solve
        int flag=1;
        for(int i=1;i<m;i++)
        {
            for(int j=i+1;j<=m;j++)
            {
                map<p,int>dx;
                for(int k=1;k<=n;k++)
                {
                    int x1=str_id[s[k][i]],x2=str_id[s[k][j]];
                    p cnt=make_pair(x1,x2);
                    if(dx.count(cnt))
                    {
                        cout<<"NO"<<endl;
                        cout<<dx[cnt]<<" "<<k<<endl;
                        cout<<i<<" "<<j<<endl;
                        flag=0;
                        goto END;
                    }
                    dx[cnt]=k;
                }
            }
        }
        END:
            if(flag)cout<<"YES"<<endl;
    }
    return 0;
}
