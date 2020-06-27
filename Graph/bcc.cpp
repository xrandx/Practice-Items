//求割点
int dfs(int u, int fa)
{
    //low[x]它记录的是在这棵DFS树上编号为x的节点所能够达到的最早的节点。
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!pre[v])
        {
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            //如果lowu==pre[v],光凭这一条u仍然是割点
            //>就更加了

            //lowv ,v及其后代能返回的最小祖先pre值，没有则返回自己 即lowv > pre[u] 则(u,v)是割边
            //而且还知道了u是割点
            if(lowv >= pre[u])
            {
                iscut[u] = true;
            }
        }
        else if(pre[v] < pre[u] && fa != v)//如果访问过就判断是不是后向边，
        {
            lowu = min(pre[v], lowu);
        }
    }
    //if(fa == -1 && child > 1) iscut[u] = true; 不这样判断是因为lowu一开始等于pre[u]
    if(fa < 0 && child == 1) iscut[u] = false;
    //如果是叶子结点，一开始是memset(iscut, 0, sizeof(iscut))

    low[u] = lowu;
    return lowu;
}



//求点双连通分量
struct Edge
{
    int u, v;
};

int pre[maxn], iscut[maxn], bccno[maxn], dfs_clock, bcc_cnt;//bccno记录每个点的bcc编号
vector <int> G[maxn], bcc[maxn];//bcc储存双连通分量的点
stack<Edge> S;



int dfs(int u, int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        Edge e = (Edge){u, v};
        /*栈中存储的是边而不是点!!!*/
        /*因为割顶明显不可能属于任何一个点双，所以割顶的bccno无意义。*/
        if(!pre[v])
        {
            S.push(e);//没有访问过的，就压栈，把沿途遍历到的边都加入栈（也就是第一次遍历所有的点）
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if(lowv >= pre[u])//必存在割点  若大于则还存在割边(u, v)
            {
                //若发现了一个割点，说明当前栈中已经保存了点双的所有边。
                iscut[u] = true;
                bcc_cnt++;//从1开始
                bcc[bcc_cnt].clear();//清空准备储存
                for(;;)
                {
                    Edge x = S.top(); S.pop();
                    if(bccno[x.u] != bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.u);//第bcc_cnt个连通分量有点加入
                        bccno[x.u] = bcc_cnt;
                    }
                    if(bccno[x.v] != bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v] = bcc_cnt;
                    }
                    if(x.u == u && x.v == v) break;
                }//把边集中涉及到的点全部取出来，把他们的bccno[]设置成当前的bcc_cnt
            }
        }
        else if(pre[v] < pre[u] && v != fa)//反向边
        {
            S.push(e);//也许割点v此时被push
            lowu = min(lowu, pre[v]);//反向边更新
        }
    }
    if( fa < 0 && child == 1)   iscut[u] = 0;
    return lowu;
}


void find_bcc(int n)
{
    memset(pre, 0, sizeof(pre));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    dfs_clock = bcc_cnt = 0;
    for(int i = 0; i < n; i++)
        if(!pre[i]) dfs(i, -1);//怕万一有些点是孤立的
}




//边双连通！！！
void dfs(int u, int fa) 
{
    low[u] = pre[u] = ++dfs_clock;
    stakk[top++] = u;
    for (int i = 0; i < (int)G[u].size(); i++) 
    {
        int v = G[u][i];

        if (!pre[v]) 
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } 
        else if (pre[v] < pre[u] && v != fa) 
        {
            low[u] = min(low[u], pre[v]);
        }
    }
    //
    if (pre[u] == low[u]) 
    {
        while (top > 0 && stakk[top] != u) 
        {
            low[stakk[--top]] = low[u];
        }
    }
}

void find_bcc(int n) 
{
    MEM(pre); MEM(low);MEM(deg);
    dfs_clock = top = 0;
    for (int i = 1; i <= n; i++)
        if (!pre[i]) dfs(i, -1);
}