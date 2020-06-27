#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
map<string,string> M;
int main()
{
    char a[12],b[12],str[30];
    while(gets(str))
    {
        if(strcmp(str,"")==0)break;
        int i,l=strlen(str);
        for(i=0;i<l;++i)
        {
            if(str[i]==' ')break;
        }
        strncpy(a,str,i);
//        cout << a; 
        a[i]='\0';
        strncpy(b,str+i+1,l-i);
        b[l-i]='\0';
       // cout<<a<<endl<<b<<endl;
        M[b]=a;
    }

    while(cin>>b)
    {
        if(M[b]=="")
        {
            cout<<"eh"<<endl;
        }
        else
        {
            cout<<M[b]<<endl;
        }
    }
    return 0;
}

