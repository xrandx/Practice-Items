#include <stdio.h>  
#include <math.h> 

int TOR(int p)
{
	
}


int main()
{

	int n;
	int max;
	while(~scanf("%d", &n))
	{
		
		max = 0;
		int a[n];
		int T[n];
		int i,j;
		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
			if(a[i] > max)	
				max = a[i];
		}
		int result[max];
		for(i=0; i<max; i++)
		{
			result[i] = 3*i*i+3*i+1;
		}
		int end;
		for(i=0; i<n; i++)
		{
			end = 3*a[i]*a[i]+3*a[i]+1;
			for(j=0; j<=end; j++)
			{
				
			}
		}
	}
	return 0;
}
