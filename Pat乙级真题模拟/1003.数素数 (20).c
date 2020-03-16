#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAXN = 200000 + 10;
const int N = 10000 + 10;
int main(){
	int isprime[MAXN], primes[N];
	
	for(int i = 2; i < MAXN; i++)
		isprime[i] = 1;
	
	isprime[0] = isprime[1] = 0;
	
	for(int i = 2; i * i < MAXN; i++){
		if(isprime[i] == 1){
			for(int j = i + i; j < MAXN; j += i)
				isprime[j] = 0;
		}
	}
	
	for(int i = 2, cnt = 1; i < MAXN; i++){
		if(isprime[i] == 1)
			primes[cnt++] = i;
	}
	
	int m, n;
	while(~scanf("%d %d", &m, &n)){
		int cnt = 1;
		for(int i = m; i <= n; i++, cnt++){
			if(cnt % 10 == 1){
				if(cnt > 10){
					printf("\n");
				}
				printf("%d", primes[i]);
			}
			else
				printf(" %d", primes[i]);
		}

		
	}

	return 0;
}
