#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i++)
        {
            char s[40];
            scanf("%s", &s);
            int num = strlen(s);
            int half = num / 2;
            int c = 0, a = 0, b = 0;
            for(int j = 0; j < num; j++)
            {
                c = 10 * c + s[j] - '0';
            }
            a = c / pow(10, half);
            b = c % (int)pow(10, half);
            if( a * b != 0 && c % (a * b) == 0 )
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
