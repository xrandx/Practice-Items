#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int TOR(int p)
{
	double delt = (9.0 - 12.0*(1.0 - p));
	double sqd = sqrt(delt);
	double root = (-3.0 - sqd)/6.0;
	int flag;
	double flag1;
	flag = (int)root;
	flag1 = root - double(flag);
	if(delt >= 0)
	{
		if(flag1 != 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}


int main()
{

	int n;
	int i;
	int max;
	while(~scanf("%d", &n))
	{
		int a[n];
		int T[n];
		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}
		for(i=0; i<n; i++)
		{
			if(a[i]==2)
				T[i] = 0;
			else
				T[i] = TOR(a[i]);
		}
		for(i=0; i<n; i++)
		{
			if(T[i])
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		memset(a,0,sizeof(a));
		memset(T,0,sizeof(T));
	}
	return 0;
}
