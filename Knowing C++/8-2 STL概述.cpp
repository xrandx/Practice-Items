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
	if(p != a.end())//���û���ҵ��ͷ��� a.end() 
		cout << "Yep "<< *p << endl;
	else
		cout << "Not found" << endl;
	p = find(a.begin()+1, a.end()-2,1); //������ [1,2,3,4] ����[2,3) 
	
	int array[10];
	for(int i = 0; i < 10; i++)
		array[i] = 5 * i;
	int *pp = find(array, array + 3, 200);//�������ǵ����� �Ҳ�������lastҲ����  array + 3
	cout << *pp << *(array + 3) << endl;
	return 0;
}
