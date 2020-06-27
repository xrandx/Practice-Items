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
//freopen("date.in","r",stdin);  //重定向所有标准的输入为文件输入
//freopen("date.out","w",stdout);//重定向所有标准的输出为文件输出
//fclose(stdout);//输出结束
//freopen("date.in","r",stdin);  //重定向所有标准的输入为文件输入
//freopen("date.out","w",stdout);//重定向所有标准的输出为文件输出
//fclose(stdout);//输出结束

