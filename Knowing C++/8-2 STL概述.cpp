#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> a;
	for(int i = 0; i < 4; i++)
		a.push_back(i+1);
	vector<int>::iterator p = find(a.begin(), a.end(), 2);
	if(p != a.end())//如果没有找到就返回 a.end() 
		cout << "Yep "<< *p << endl;
	else
		cout << "Not found" << endl;
	p = find(a.begin()+1, a.end()-2,1); //容器是 [1,2,3,4] 查找[2,3) 
	
	int array[10];
	for(int i = 0; i < 10; i++)
		array[i] = 5 * i;
	int *pp = find(array, array + 3, 200);//数组名是迭代器 找不到返回last也就是  array + 3
	cout << *pp << *(array + 3) << endl;
	return 0;
}
