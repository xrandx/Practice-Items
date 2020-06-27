#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int sum = 0;
	int a[3] = {1 , 2 , 3};
	for(int i = 2; i >= 0; i--)
	{
		sum += a[i] * pow(10, i);
	}
	cout << sum;
}
