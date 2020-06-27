//����
int dfs(int u, int fa)
{
    //low[x]����¼���������DFS���ϱ��Ϊx�Ľڵ����ܹ��ﵽ������Ľڵ㡣
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
            //���lowu==pre[v],��ƾ��һ��u��Ȼ�Ǹ��
            //>�͸�����

            //lowv ,v�������ܷ��ص���С����preֵ��û���򷵻��Լ� ��lowv > pre[u] ��(u,v)�Ǹ��
            //���һ�֪����u�Ǹ��
            if(lowv >= pre[u])
            {
                iscut[u] = true;
            }
        }
        else if(pre[v] < pre[u] && fa != v)//������ʹ����ж��ǲ��Ǻ���ߣ�
        {
            lowu = min(pre[v], lowu);
        }
    }
    //if(fa == -1 && child > 1) iscut[u] = true; �������ж�����Ϊlowuһ��ʼ����pre[u]
    if(fa < 0 && child == 1) iscut[u] = false;
    //�����Ҷ�ӽ�㣬һ��ʼ��memset(iscut, 0, sizeof(iscut))

    low[u] = lowu;
    return lowu;
}



//���˫��ͨ����
struct Edge
{
    int u, v;
};

int pre[maxn], iscut[maxn], bccno[maxn], dfs_clock, bcc_cnt;//bccno��¼ÿ�����bcc���
vector <int> G[maxn], bcc[maxn];//bcc����˫��ͨ�����ĵ�
stack<Edge> S;



int dfs(int u, int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        Edge e = (Edge){u, v};
        /*ջ�д洢���Ǳ߶����ǵ�!!!*/
        /*��Ϊ����Բ����������κ�һ����˫�����Ը��bccno�����塣*/
        if(!pre[v])
        {
            S.push(e);//û�з��ʹ��ģ���ѹջ������;�������ı߶�����ջ��Ҳ���ǵ�һ�α������еĵ㣩
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if(lowv >= pre[u])//�ش��ڸ��  �������򻹴��ڸ��(u, v)
            {
                //��������һ����㣬˵����ǰջ���Ѿ������˵�˫�����бߡ�
                iscut[u] = true;
                bcc_cnt++;//��1��ʼ
                bcc[bcc_cnt].clear();//���׼������
                for(;;)
                {
                    Edge x = S.top(); S.pop();
                    if(bccno[x.u] != bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.u);//��bcc_cnt����ͨ�����е����
                        bccno[x.u] = bcc_cnt;
                    }
                    if(bccno[x.v] != bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v] = bcc_cnt;
                    }
                    if(x.u == u && x.v == v) break;
                }//�ѱ߼����漰���ĵ�ȫ��ȡ�����������ǵ�bccno[]���óɵ�ǰ��bcc_cnt
            }
        }
        else if(pre[v] < pre[u] && v != fa)//�����
        {
            S.push(e);//Ҳ����v��ʱ��push
            lowu = min(lowu, pre[v]);//����߸���
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
        if(!pre[i]) dfs(i, -1);//����һ��Щ���ǹ�����
}




//��˫��ͨ������
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