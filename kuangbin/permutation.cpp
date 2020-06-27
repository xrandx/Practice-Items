#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int main()
{
	for(int i = 1; i <= 10; i++)
		v.push_back(i);
	for(int i = 1; i <= 10; i++)
		cout << v[i-1] << " ";
	cout << endl;
	for(int j = 1; j <= 10; j++)
	{
		next_permutation(v.begin(), v.end());
		for(int i = 1; i <= 10; i++)
			cout << v[i-1] << " ";
		cout << endl;
	}
}
