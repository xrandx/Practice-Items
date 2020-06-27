// File Name: 11997.cpp
// Author: zlbing
// Created Time: 2013/3/8 20:19:01

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<n+1;i++)
#define MAXN 1000
int G[MAXN][MAXN];
int k;
struct Item{
    int s,b;
    bool operator <(const Item& r)const{
        return s>r.s;
    }
};
void merge(int *A,int *B,int *C){
    int cnt=0;
    priority_queue<Item> Q;
    for(int i=0;i<k;i++)Q.push((Item){A[i]+B[0],0});
    while(!Q.empty()){
        Item t=Q.top();
        Q.pop();
        C[cnt++]=t.s;
        if(t.b+1<k)Q.push((Item){t.s+(B[t.b+1]-B[t.b]),t.b+1});
        if(cnt==k)break;
    }
    //for(int i=0;i<k;i++)printf("%d ",C[i]);
}
int main(){
    while(~scanf("%d",&k))
    {
        REP(i,k){
            REP(j,k)
                scanf("%d",&G[i][j]);
            sort(G[i],G[i]+k);
        }
        REP1(i,k-1)merge(G[0],G[i],G[0]);
        REP(i,k)
            if(i==0)printf("%d",G[0][i]);
            else printf(" %d",G[0][i]);
        printf("\n");
    }
    return 0;
}
