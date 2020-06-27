#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 206;



struct Node
{
    int v[3];
    int dist;
    bool operator < (const Node& rhs) const
    {
        return dist > rhs.dist;
    }
};

int cap[3];
int vis[maxn][maxn], ans[maxn];



void update_ans(const Node& u)
{
    for(int i = 0; i < 3; i++)
    {
        int d = u.v[i];
        if(ans[d] < 0 || u.dist < ans[d])
            ans[d] = u.dist;
    }
}

void bfs(int a, int b, int c, int d)
{
    cap[0] = a; cap[1] = b; cap[2] = c;
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    priority_queue<Node> q;

    Node start;
    start.v[0] = 0; start.v[1] = 0; start.v[2] = c;
    start.dist = 0;
    q.push(start);

    vis[0][0] = 1;
    while(!q.empty())
    {
        Node u = q.top();
        q.pop();
        update_ans(u);
        if(ans[d] >= 0) break;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(i != j) //取不同两瓶
        {
            if(u.v[i] == 0 || u.v[j] == cap[j]) continue;//从i倒进j所以 跳过
            int amount = min(cap[j], u.v[i] + u.v[j]) - u.v[j];//倒进j的量
            Node u2;
            memcpy(&u2, &u, sizeof(u));
            u2.dist = u.dist + amount;
            u2.v[i] -= amount;
            u2.v[j] += amount;
            if(!vis[u2.v[0]][u2.v[1]])
            {
                vis[u2.v[0]][u2.v[1]] = 1;
                q.push(u2);
            }
        }

    }
    while(d >= 0)
        {
            if(ans[d] >= 0)
            {
                printf("%d %d\n", ans[d], d);
                return;
            }
            d--;
        }
}



int main()
{
    int t;
    int a, b, c, d;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);

        bfs(a, b, c, d);
    }
    return 0;
}
