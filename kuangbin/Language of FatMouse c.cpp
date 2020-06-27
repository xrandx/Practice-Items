#include<map>
#include<string>
#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	map<string,string> m;
	char a[10],b[10];
	char x[10];
	//freopen("fatmouse.txt","r",stdin);
//	scanf("%s",&a);
//	cout<<a<<endl;
	while(scanf("%c",&a[0])!=EOF&&a[0]!='\n')
	{
		scanf("%s",a+1);
		scanf("%s",&b);		
		getchar();
		
		m[b]=a;
		//cout<<b<<" "<<m[b]<<endl;
	}
	//cout<<"here"<<endl;
	//getchar();
	//getchar();
	while(scanf("%s",&x)!=EOF)
	{
		//cout<<x<<endl;
		if(m.count(x))
			cout<<m[x]<<endl;
		else
			cout<<"eh"<<endl;
		//getchar();
	}
	return 0;
}

