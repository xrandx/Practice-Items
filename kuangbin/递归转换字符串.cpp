#include <stdio.h>
#include <string.h>
void trans(char s[], int n, int i)
{
	if(i)
	{
		s[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
		trans(s, n, i);
	}
	else
	{
		return;
	}
}


int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int i = n;
		int count = 0;
		while(i)
		{
			i /= 10;
			count++;
		}
		printf("%dÎ»Êı\n", count);
		char s[count];
		trans(s, n, count);
		s[count] = '\0';
		printf("%s\n", s);
	}
}
