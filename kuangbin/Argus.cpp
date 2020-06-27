#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node
{
	int qnum, per, time;
	bool operator < (const node & a) const
	{
		if(time == a.time)
			return qnum > a.qnum;
		return time > a.time;
	}
};



int main()
{
	string cmd;
	node one;
	priority_queue < node > pq;
	while(cin >> cmd && cmd[0] != '#')
	{
		cin >> one.qnum >> one.per;
		one.time = one.per;
		pq.push(one);
	}
	int t;
	cin >> t;
	while(t--)
	{
		one = pq.top();
		cout << one.qnum << "\n";
		pq.pop();
		one.time += one.per;
		pq.push(one);
	}
	return 0;
}
