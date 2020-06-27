#include <stdio.h>

int main()
{
    int rank = 1;
    int sum = 1;
    int a[480];

    a[1] = 1;
    for(int i = 2; i <= 480; i++)
    {
        if(i - sum  == 1) a[i] = 1;
        else if(i - sum == rank + 1)
        {
            a[i] = 1;
            rank++;
            sum += rank;
        }
        else
        {
            a[i] = a[i - rank] + a[i - rank - 1];
        }
    }

	printf("ÊäÈëÑî»ÔÈı½Çº¯Êı£º\n");
    int n;
    while(~scanf("%d", &n) && n)
    {
        for(rank = 1, sum = 0; rank <= n; rank++)
        {
            printf("%d", a[sum + 1]);
            for(int i = 2; i <= rank; i++)
            {
                printf(" %d", a[i + sum]);
            }
            printf("\n");
            sum += rank;
        }
        printf("\n");
    }
}
