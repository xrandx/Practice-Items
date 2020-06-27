#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	char str[50], str1[50];
	scanf("%[^ ]", str);
	getchar();
	scanf("%[^\n]s", str1);
	cout << str << endl;
	printf("%s\n", str1);
}
