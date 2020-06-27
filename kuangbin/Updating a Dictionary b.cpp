#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
map<string,string> d[2];
string t[105];
void print(char c,int n)
{
	cout<<c;
	sort(t,t+n);
	int i;
	for(i=0;i<n-1;i++)
	{
		cout<<t[i]<<",";
	}
	cout<<t[i]<<endl;
}

int main()
{
	int n,i;
	//freopen("update a dictionary.txt","r",stdin);
	
	cin>>n;
	string a,b,str;
	while(n--)
	{	
		d[0].clear();d[1].clear();
		for(int k=0;k<2;k++)
		{
			cin>>str;
			int x=str.length();
			i=1;
			while(x>2&&i<x)
			{
				a.clear();b.clear();
				while(str[i]!=':')
					a+=str[i++];
				while(str[i]!=','&&str[i]!='}')
					b+=str[i++];
				i++;
				//cout<<a<<" "<<b<<endl;
				d[k][a]=b;
			}
		}
		map<string,string>::iterator it;
		int c1=0,c2=0,c3=0;	
        for(it = d[1].begin(); it != d[1].end(); ++it)
            if(!d[0].count(it->first)) t[c1++] = it->first;
        if(c1) print('+', c1);

        for(it = d[0].begin(); it != d[0].end(); ++it)
            if(!d[1].count(it->first)) t[c2++] = it->first;
        if(c2) print('-', c2);

        for(it = d[1].begin(); it != d[1].end(); ++it)
            if(d[0].count(it->first) && d[0][it->first] != it->second) t[c3++] = it->first;
        if(c3) print('*', c3);

        if(!(c1 || c2 || c3)) puts("No changes");
        puts("");

	}
	return 0;
}

