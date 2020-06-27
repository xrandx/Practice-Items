#include <iostream>

int cal(int n, int m)
 {
 int i, a, b, p;
 if(n<m){i=m;m=n;n=i;}
 p=1;
 a=n-m<m?n-m:m;
 b=n-m>m?n-m:m;
 for(i=1; i<=a; i++)
p+=p*b/i;
return p;
}

int main()
{
	std::cout << cal(1,3);
}
