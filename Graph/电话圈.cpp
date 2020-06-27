#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

const int maxn = 50;
int r[maxn][maxn];
int p[maxn];
set<string> ids;
map<string, int> nametoid;
string idtoname[maxn];


int id(string name)
{
    if(ids.count(name))
        return nametoid[name];
    else
    {
        ids.insert(name);
        idtoname[ids.size()] = name;
//        cout << idtoname[ids.size()] << endl;
        return nametoid[name] = ids.size();
    }

}

int findset(int x)
{
    return p[x] == x? x : p[x] = findset(p[x]);
}

inline int reset(int n)
{
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int kase = 1;
    while(1)
    {
        int n, m;
        char from[20], to[20];
        scanf("%d%d", &n, &m);
        if(n + m == 0) break;
        memset(p, 0, sizeof(p));
        memset(r, 0, sizeof(r));
        ids.clear();
        nametoid.clear();
        vector< vector<string> > circle(maxn);
        for(int i = 1; i <= m; i++)
        {
            scanf("%s%s", from, to);
            int x = id(from);
            int y = id(to);
//            cout << from << x << to << y <<endl;
            r[x][y] = 1;
        }

        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    r[i][j] = r[i][j] || (r[i][k] && r[k][j]);
        reset(n);

        int meta, meta2;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(r[i][j] && r[j][i])
                {
                    meta = findset(i);
                    meta2 = findset(j);
                    if(meta != meta2)
                        p[meta2] = meta;
                }
            }

        }


        for(int i = 1; i <= n; i++)
        {
            int meta = findset(i);
            circle[meta].push_back(idtoname[i]);
        }
        if(kase != 1) cout << "\n";
        cout << "Calling circles for data set " << kase++ << ":\n";
//        for(int i = 1; i <= n; i++)
//        {
//            for(int j = 1; j <= n; j++)
//                cout << r[i][j] << " ";
//            cout << endl;
//        }

//        for(int k = 1; k <= n; k++)
//        {
//            cout << k << " : " << p[k] << endl;
//        }
        for(int i = 1; i <= n; i++)
        {
            if(!circle[i].empty())
            {
                for(vector<string>::iterator it = circle[i].begin(); it != circle[i].end(); it++)
                {
                    if(it != circle[i].begin())
                        cout << ", ";
                    cout << *it;
                }
                cout << "\n";
            }
        }


    }
    return 0;
}

