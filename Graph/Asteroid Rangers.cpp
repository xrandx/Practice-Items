#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 50 + 6;
const int maxks = maxn * (maxn - 1) / 2;
const double eps = 1e-8;
int n;
int nks;
int p[maxn];

struct KineticPoint
{
    double x, y, z;
    double dx, dy, dz;
    void read()
    {
        scanf("%lf%lf%lf%lf%lf%lf", &x, &y, &z, &dx, &dy, &dz);
    }
} kp[maxn];

struct KineticSegment
{
    int u, v;
    double a, b, c;
    bool operator < (const KineticSegment& rhs) const
    {
        return c - rhs.c < 0;
    }
}ks[maxks];

struct Event
{
    double t;
    int newks, oldks;
    Event(double _t, int _newks = 0, int _oldks = 0): t(_t), newks(_newks), oldks(_oldks){}

    bool operator < (const Event& rhs) const
    {
        return t - rhs.t < 0;
    }

};

vector<Event> events;

int findset(int x){return p[x] == x? x : p[x] = findset(p[x]);}
void init_ufs()
{
    for(int i = 0; i < n; i++)
    {
        p[i] = i;
    }
}
double sqr(const double& x){ return x * x;}
void make_segments()
{
    nks = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            ks[nks].u = i; ks[nks].v = j;
            ks[nks].a = sqr(kp[i].dx - kp[j].dx) + sqr(kp[i].dy - kp[j].dy) + sqr(kp[i].dz - kp[j].dz);
            ks[nks].b = 2 * ((kp[i].dx - kp[j].dx) * (kp[i].x - kp[j].x) + (kp[i].dy - kp[j].dy) * (kp[i].y - kp[j].y)
                           + (kp[i].dz - kp[j].dz) * (kp[i].z - kp[j].z));
            ks[nks].c = sqr(kp[i].x - kp[j].x) + sqr(kp[i].y - kp[j].y) + sqr(kp[i].z - kp[j].z);
            nks++;
        }
    }
    sort(ks, ks + nks);
}

void make_events()
{
    //组合每条边 把他们取代对方的时间存入event
    events.clear();
    for(int i = 0; i < nks; i++)
    {
        for(int j = i + 1; j < nks; j++)
        {
            int s1 = i, s2 = j;//因为排序 s1的c更大 也就是初始的长度大
            if(ks[s1].a - ks[s2].a < 0) s1 = j, s2 = i;//s1换为a更大的
            double a = ks[s1].a - ks[s2].a;
            double b = ks[s1].b - ks[s2].b;
            double c = ks[s1].c - ks[s2].c;
            if(fabs(a) < eps) //a等于0 bt + c = d1 - d2
            {
                if(fabs(b) < eps) continue; //b = 0 相对长度不变
                if(b > 0)//说明s2相对变小 换为s1
                {
                    b = -b, c = -c; // 方程两边加负号 斜率为负 方便判断零点是否大于0
                    swap(s1, s2);
                }
                if(c > 0)events.push_back(Event(-c / b, s1, s2)); //添加零点
                continue;
            }
            double delta = b * b - 4 * a * c;
            if(delta < eps) continue; //无零点
            delta = sqrt(delta);
            double t1 = - (b + delta) / (2.0 * a);
            double t2 = (-b + delta) / (2.0 * a);
            //前面处理了 所以开口向上 t1 < t2
            //t1>0 根有意义 s1-s2递减 自零点后s1相对减小 加入mst新边
            //t2>0 s1-s2递增 自零点后s2相对减少 同理
            if(t1 > 0) events.push_back(Event(t1, s1, s2));
            if(t2 > 0) events.push_back(Event(t2, s2, s1));
            }
    }
    sort(events.begin(), events.end());
}

int solve()
{
    init_ufs();
    int ans = 1;
    int pos[maxks]; // 储存边在MST的位置
    int e[maxn]; //储存MST每一条边对应的边的位置
    int idx = 1;
    memset(pos, 0, sizeof(pos));

    for(int i = 0; i < nks; i++)
    {
        int u = findset(ks[i].u), v = findset(ks[i].v);
        if(u != v)
        {
            p[v] = u;
            pos[i] = idx;
            e[idx++] = i;
        }
        if(idx == n)
            break;
    }
    for(int i = 0; i < events.size(); i++)//按时间顺序一条一条改变MST
    {
        if(pos[events[i].oldks] && !pos[events[i].newks]) //老边在MST 新边不在
        {
            int oldpos = pos[events[i].oldks];
            if(!oldpos) continue;
            init_ufs();
            //连通除了要换的边的MST的边
            for(int j = 1; j < n; j++)
            {
                if(j != oldpos)
                {
                    int u = findset(ks[e[j]].u);
                    int v = findset(ks[e[j]].v);
                    if(u != v)
                        p[v] = u;
                }
            }
            int u = findset(ks[events[i].newks].u);
            int v = findset(ks[events[i].newks].v);
            if(u != v) //不在同一个连通分量
            {
                p[v] = u;
                pos[events[i].newks] = oldpos;
                pos[events[i].oldks] = 0;
                e[oldpos] = events[i].newks;
                ans++;
            }

        }

    }
    return ans;

}
int main()
{
//    freopen("in.txt", "r", stdin);
    int kase = 0;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
            kp[i].read();
//        cout << kp[2].z << endl;
        make_segments();
        make_events();
        int ans = solve();
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
