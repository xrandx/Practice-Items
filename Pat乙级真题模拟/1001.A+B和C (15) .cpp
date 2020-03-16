#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *fp;
	fp = freopen("test.txt", "r", stdin);
	long long a, b ,c;
	int n;
	while(scanf("%d", &n) != EOF){
		for(int cnt = 1; cnt <= n; cnt++){
			printf("Case #%d: ", cnt);
			scanf("%lld %lld %lld", &a, &b, &c);
			long long tmp = c - b;
			if(a > tmp)
				printf("true\n");
			else
				printf("false\n");
		}
				
	}
	
	return 0;
}
