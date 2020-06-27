#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		int com = 0, num;
		int sf = 1, qf = 1, pf = 1;
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;
		for(int i = 0; i < n; i++)
		{
			cin >> com >> num;
			if(com == 1)
			{
				if(sf)
					s.push(num);
				if(qf)
					q.push(num);
				if(pf)
					p.push(num);
			}
			else if(com == 2)
			{
				if(s.empty() || s.top() != num)
					sf = 0;
				else s.pop();
				if(q.empty() || q.front() != num)
					qf = 0;
				else q.pop();
				if(p.empty() || p.top() != num)
					pf = 0;
				else p.pop();
			}
		}
		switch(sf + qf + pf)
		{
			case 0:
				cout << "impossible" << endl;
				break;
			case 1:
				if(sf == 1)
					cout << "stack" << endl;
				else if(qf == 1)
					cout << "queue" << endl;
				else if(pf == 1)
					cout << "priority queue" << endl;
				break;
			case 2:
			case 3:
				cout << "not sure" << endl;
		}



	}
	return 0;
}
