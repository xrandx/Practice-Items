#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
using namespace std;

deque<int> dq;
vector<int> dis;

int main()
{
	int n;
	while(~scanf("%d", &n) && n)
	{
		dq.clear();
		dis.clear();
		if(n == 1)
		{
			cout << "Discarded cards:" << endl;
			cout << "Remaining card: 1" <<endl;
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			dq.push_back(i);
		}
		while(1)
		{
			if(dq.size() == 1)
				break;
			dis.push_back(dq.front());
			dq.pop_front();
			if(dq.size() == 1)
				break;
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << "Discarded cards:";
		vector<int>::iterator it = dis.begin();
		cout << " "<< *it;
		for(it++; it != dis.end(); it++)
		{
			cout << ", "<<*it;
		}
		cout << endl << "Remaining card: " << *dq.begin() << endl;
	}
} 
