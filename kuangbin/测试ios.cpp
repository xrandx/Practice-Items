#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	freopen("dataout.txt","r", stdin);
	int a;
	int start = clock();
	for(int i = 0; i < 1000000; i++)
	{
//		scanf("%d\n", &a);
		cin >> a;
//		printf("%d", i);
	}
	printf("%.3lf\n",double(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}
//freopen("date.in","r",stdin);  //�ض������б�׼������Ϊ�ļ�����
//freopen("date.out","w",stdout);//�ض������б�׼�����Ϊ�ļ����
//fclose(stdout);//�������
//freopen("date.in","r",stdin);  //�ض������б�׼������Ϊ�ļ�����
//freopen("date.out","w",stdout);//�ض������б�׼�����Ϊ�ļ����
//fclose(stdout);//�������

