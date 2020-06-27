#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include <vector>


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
//优先队列中的元素
struct Item
{
	int qnum, period, time;
	bool operator < (const Item& a) const
	{
		return (time > a.time || (time == a.time && qnum > a.qnum));
	}
};

int main()
{
	priority_queue<Item> pq;
	char s[20];
	while(scanf("%s", s) && s[0] != '#')
	{
		Item tmp;
		cin >> tmp.qnum >> tmp.period;
		tmp.time = tmp.period;
		pq.push(tmp);
	}
	int K;
	cin >> K;
	while(K--)
	{
		Item tmp;
		tmp = pq.top();
		pq.pop();
		cout << tmp.qnum << endl;
		tmp.time += tmp.period;
		pq.push(tmp);
	}
	return 0;
}
