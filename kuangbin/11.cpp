#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include <vector>
#include<cstdio>

using namespace std;

typedef long long ll;
const int coff[3] = {2, 3, 5};

int main()
{
	set<ll> Set;
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	pq.push(1);
	Set.insert(1);
	for(int i = 1; ;i++)
	{
		ll x = pq.top();
		pq.pop();
		if(i == 1500)
		{
			cout << "The 1500'th ugly number is "<< x << "." << endl;
			break;
		}
		for(int j = 0; j < 3; j++)
		{
			ll n = x * coff[j];
			if(!Set.count(n))
			{
				Set.insert(n);
				pq.push(n);
			}
		}
	}
	
	return 0;
	
	/*int n;
	set<int>::iterator it;
	Set.insert(1);
	q.push(2);
	q.push(3);
	q.push(5);
	while(Set.size() != 1500)
	{
		n = q.front();
		q.push(2 * n);
		q.push(3 * n);
		q.push(5 * n);
		Set.insert(n);
		q.pop();
	}
	for(it = Set.begin(); it != Set.end(); it++)
		cout << *it << endl;*/
}


