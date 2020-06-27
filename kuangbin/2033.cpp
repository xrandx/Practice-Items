#include <stdio.h>


int main()
{

	int n;
	int i,j;
	int h,m,s;
	int flag;
	int sum;
	while(~scanf("%d", &n))
	{
		int a[n][6];
		int s[n][3];
		for(i=0; i<n; i++)
		{
			for(j=0; j<6; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		flag = 0;
		for(i=0; i<n; i++)
		{
			s[i][0] = a[i][0] + a[i][3];
			for(j=2; j>1; j--)
			{
				sum = a[i][j] + a[i][j+3];
				if(sum <= 59)
				{
					s[i][j] = sum + flag ;
					flag = 0;
				}
				else
				{
					s[i][j] = sum - 60 + flag;
					flag = 1;
				}
				
			}
		}
	}
	return 0;
}
