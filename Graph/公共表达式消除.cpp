#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;
const int maxn = 60000;
int cas;
char line[maxn * 5], *p;
int vis[maxn];
int cnt;

struct tree
{
    string r;
    int left;
    int right;
    bool operator < (const tree& rhs ) const 
    {
        if(r != rhs.r)
            return r < rhs.r;
        if(left != rhs.left)
            return left < rhs.left;
        return right < rhs.right;
    }
}T[maxn];

map<tree, int> dict;



int retID()
{
    int id = ++cnt;
    tree& ref = T[id];
    ref.r = "";
    ref.left = ref.right = -1;
    while(*p >= 'a' && *p <= 'z')
    {
        ref.r.push_back(*p);
        p++; 
    }
    if(*p == '(')
    {
        p++;
        ref.left = retID();p++;
        ref.right = retID();p++;
    }
//    cout << ref.r << ref.left << ref.right << "\n";
    
    if(dict.count(ref))
    {
    	cnt--;
        return dict[ref];
	}
        return dict[ref] = id;
}

void print(int id)
{
//	cout << id << " == id \n";
	if(vis[id] == cas)
	        cout << id;
    else
    {
        vis[id] = cas;
        cout << T[id].r;
        if(T[id].left != -1 )
        {
            cout << "(";
            print(T[id].left);
            cout << ",";
            print(T[id].right);
            cout << ")";
        }
    }

}

int main()
{
    int n;
    while(cin >> n && n)
    {
//    	getchar();
        for(cas = 1; cas <= n; cas++)
        {
        	dict.clear();
        	cnt = 0;
//           	scanf("%s", &line);
			cin >> line;
            p = line;
            print(retID());
            cout << "\n";
        }
    }
    return 0;
}
