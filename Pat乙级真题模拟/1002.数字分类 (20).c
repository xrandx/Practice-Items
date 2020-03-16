#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	FILE *fp;
	fp = freopen("test.txt", "r", stdin);
	int a[5], n, tmp, cnt, flag[5], total = 0;
	memset(flag, 0, sizeof(flag));
	memset(a, 0, sizeof(a));

	while(~scanf("%d", &n)){
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			int op = tmp % 5;
			switch(op){
				case 0:
					if(tmp % 10 == 0){
						flag[0] = 1;
						a[0] += tmp;
					}
					break;
				case 1:
					flag[1] = 1;
					if(cnt % 2 == 0){
						a[1] += tmp;
					}
					else{
						a[1] -= tmp;
					}
					cnt++;
					break;
				case 2:
					flag[2] = 1;
					a[2]++;
					break;
				case 3:
					flag[3] = 1;
					a[3] += tmp;
					total++;
					break;
				case 4:
					flag[4] = 1;
					if(tmp > a[4])
						a[4] = tmp;
					break;
				}
		}

	}
	
	for(int i = 0; i < 5; i++){
		if(i != 0)
			printf(" ");
		if(flag[i] == 0){
			printf("N");
		}
		else{
			switch(i){
			case 3:
				printf("%.1lf", 1.0 * a[3] /  total);
				break;
			default:
				printf("%d", a[i]);
			}
		}

	}
	
	return 0;
}
