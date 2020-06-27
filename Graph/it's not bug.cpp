#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 26;
const int maxm = 106;
int n, m;
typedef int Pattern[maxn];
struct Node
{
    int time, dist;
    Pattern p;
    bool operator < (const Node& rhs) const
    {
        return dist > rhs.dist;
    }

};
Node patch[maxm][2];
set<int> seta;

int hasht(Node& u)
{
    Pattern& s = u.p;
    int hashval = 0;
    for(int i = 0; i < n; i++)
    {
        hashval = s[i] + hashval * 10;
    }
    return hashval;
}

int match(Node& s, Node& h)
{
    Pattern& u = s.p;   Pattern& v = h.p;
    int flag = 1;
    for(int i = 0; i < n; i++)
    {
        if(u[i] != v[i] && v[i] != 2)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int tran(Node& s, Node& h)
{
    Pattern& u = s.p;Pattern& v = h.p;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == 2)
            continue;
        else u[i] = v[i];
    }
    s.dist = s.dist + h.time;
    return 1;
}
//void print(Node& u)
//{
//    for(int i = 0; i < n; i++)
//    {
//        cout << u.p[i];
//    }
//    cout << endl;
//}

void bfs()
{
    Node start, complete, u;
    start.dist = 0, complete.dist = INF;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        start.p[i] = 1; complete.p[i] = 0;
    }
    priority_queue<Node> q;
    seta.clear();
    q.push(start); seta.insert(hasht(start));
    while(!q.empty())
    {
//        cout << "u:";
        u = q.top(); q.pop();
//        print(u);
        if(memcmp(complete.p, u.p, sizeof(a)) == 0) break;
        seta.insert(hasht(u));
        for(int i = 0; i < m; i++)
        {
            if(match(u, patch[i][0]))
            {
                Node u2;
                memcpy(&u2, &u, sizeof(u));
                tran(u2, patch[i][1]);
//                print(u2);
                if(!seta.count(hasht(u2)))
                    q.push(u2);
            }
        }
    }
    if(memcmp(u.p, complete.p, sizeof(a)) == 0)
        cout << "Fastest sequence takes " << u.dist << " seconds.\n\n";
    else
        cout << "Bugs cannot be fixed.\n\n";
}


int main()
{
//    freopen("in.txt", "r", stdin);
    char ch; int t = 0;
    while(~scanf("%d%d", &n, &m) && (n || m))
    {
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &patch[i][0].time);
            patch[i][1].time = patch[i][0].time;
            for(int k = 0; k < 2; k++)
            {
                for(int j = 0; j < n; j++)
                {
                    scanf(" %c", &ch);
                    switch(ch)
                    {
                        case '-': patch[i][k].p[j] = 0; break;
                        case '+': patch[i][k].p[j] = 1; break;
                        case '0': patch[i][k].p[j] = 2; break;
                    }
                }
            }

        }
        cout << "Product " << ++t << "\n";
        bfs();
    }
//        Pattern one;
//        one[0] = 0; one[1] = 0; one[2] = 0;
//        cout << match(patch[0][0].p, one);
//        Pattern after;
//        memcpy(&after, &one, sizeof(one));
//        tran(after, patch[0][1].p);
//        for(int i = 0; i < n; i++)
//            cout << after[i];

//        for(int i = 0; i < m; i++)
//        {
//            for(int k = 0; k < 2; k++)
//                for(int j = 0; j < n; j++)
//                    cout << patch[i][k].p[j];
//            cout << "\n";
//        }

    return 0;
}

