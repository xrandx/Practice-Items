#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <functional>
using namespace std;
//class elem
//{
//	public:
//		int x;
//		bool operator < (const elem & a)
//		{
//			return x > a.x;
//		}
//};

//set< int, greater<int> > s;

//set< int, greater<int> >::iterator it;
int main()
{
//	freopen("in.txt", "r", stdin);
	string s1;
	int n, k, i;
	int num;

	while(~scanf("%d%d", &n, &k))
	{
		priority_queue<int, vector<int>, greater<int> > pq;
		while(!pq.empty()) pq.pop();
		while(n--)
		{
			cin >> s1;
			if(s1[0] == 'I')
			{
				cin >> num;
				pq.push(num);
				if(pq.size() > k)
					pq.pop();
			}
			else
			{
				cout << pq.top() << endl;
			}

		}

	}
	return 0;
}
