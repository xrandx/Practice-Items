#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	scanf("%s", str);
	printf("\n���룺%s\n", str);
	printf("\nԭ�ģ�", str);
	for(int i = 0; i <= strlen(str); i++)
	{
		if((str[i] >= 97 && str[i] <= 122))
			printf("%c", 26 - (str[i] - 97 - 1 )  + 95 );
		else if (str[i] >= 65 && str[i] <= 90)
			printf("%c", 26 - (str[i] - 65 - 1)   + 63 );
		else
			printf("%c", str[i]);
	}
}
