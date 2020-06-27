#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	vector<int> v(5);//每个初始化为0
	cout << v.end() - v.begin() << endl;
	vector<int> v2(5, 5);
	v2.at(4) = 6;//at有错误提示
	vector<int> v3(a, a+5);//左闭右开区间
	for(int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;
	v3.insert(v3.begin() + 2, 8);
	for(int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	vector< vector<int> > v4(6);
	for(int i = 0; i < v4.size(); i++)
		for(int j = 0; j < 6; j++ )
			v4[i].push_back(j);
	for(int i = 0; i < v4.size(); i++)
	{
		for(int j = 0; j < 6; j++ )
			cout << v4[i][j];
		cout << endl;
	}
	return 0;
}
