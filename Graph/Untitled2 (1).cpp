#include <algorithm>
#include <iostream>

using namespace std;

struct a
{
    int w;
    bool see;
    bool operator < (const a& rhs) const
    {
        if(rhs.see)
            return w < rhs.w;
        return true;
    }
}k[20];
int main()
{
    for(int i = 0; i < 10; i++)
    {
        k[i].w = i;
        i % 2 ? k[i].see = 1 : k[i].see = 0;
    }
    sort(k, k+9);
for(int i = 0; i < 10; i++)
    cout << k[i].w << k[i].see << "\n";
}
