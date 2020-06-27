#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	char tmp[100];
	do
	{
		scanf("%s", tmp);
		if(strlen(tmp) > strlen(s))
		{
			strcpy(s, tmp);
		}
	}while(getchar() != '\n');
	printf("%s", s);
	return 0;
}
