#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
struct node
{
	string ms;
	string para;
	int val;
	bool operator < (const node & a) const
	{
		return val > a.val;
	}
};

priority_queue< node >  pq;

int main()
{
	string cmd;
	node a;
	while(cin >> cmd)
	{
		if(cmd[0] == 'G')
		{
			if(pq.empty())
				cout << "EMPTY QUEUE!" << endl;
			else
			{
				cout << pq.top().ms << " " << pq.top().para << endl;
				pq.pop();
			}
		}
		else
		{
			cin >> a.ms >> a.para >> a.val;
			pq.push(a);
		}
	}
	return 0;
}

