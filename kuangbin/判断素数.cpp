#include <stdio.h>
#include <math.h>


int main()
{
	int n;
	while(~scanf("%d", &n) && n > 1)
	{
		int flag = 1;
		if(n == 2)
			printf("%d��������\n", n);
		else
		{
			for(int i = 2; i <= sqrt(n); i++)
			{
				if(n % i == 0)
				{
					flag = 0;
					printf("%d�Ǻ�����\n", n);
					break;
				}
			}
			if(flag)
			printf("%d��������\n", n);
		}

	}
	return 0;
}
