/*
   hdu 1075
   ???:map??,????O(logn)
   ???:??? ??????
   ????????!
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
#define eps 1e-9
#define pi acos(-1)
#define INF 0x7fffffff
#define inf -INF
#define MM 12900
#define N 50
using namespace std;
typedef long long ll;
const int _max = 5e4 + 10;
map<string,string>mp;

string s,a,b;

int main(){
	freopen("What Are You Talking About.txt", "r", stdin);
    cin>>s;
    while(cin>>a&&a!="END"){
        cin>>b;
        mp[b] = a;
    }
    cin>>s;//cout<<s<<endl;
    getchar();
    a="";
    while(getline(cin,s)&&s!="END"){
     for(int i = 0; i < s.length();++ i){
        if(islower(s[i])){
           a+=s[i];
        }
        else {
          if(mp.find(a)!=mp.end()) cout<<mp[a];
          else cout<<a;
          a="";
          printf("%c",s[i]);
        }
     }
     cout<<endl;
    }
    return 0;
}


