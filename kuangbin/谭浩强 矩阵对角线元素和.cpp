#include <stdio.h>
int main()
{
	int a[3][3];
	printf("����3 * 3����������ÿ��Ԫ���Կո�ָ���ÿ��Ҫ����\n");
	for(int i = 0; i < 3; i++)
	{
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}
	printf("%d", a[0][0] + a[1][1] + a[2][2]);
}
