#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		v.clear();
		for(int i = 0; i < n; i++)
			v.push_back(i + 1);
		sort(v.begin(), v.end());
		m--;
		while(m--)
		{
			next_permutation(v.begin(), v.end());
		}
		printf("%d", v[0]);
		for(int i = 1; i < n; i++)
		{
			printf(" %d",v[i]);
		}
		printf("\n");
	}
}
