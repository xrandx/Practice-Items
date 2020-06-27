#include<iostream>  
#include<string.h>
using namespace std;  
bool chess[9][9];
bool flag[9];
int exist;
int n, k;

void DFS(int row, int num)
{
	int j;
	if(num == k)
	{
		exist++;
		return;
	}
	if(row > n)
		return;
	for(j=1; j<=n; j++)
	{
		if(chess[row][j] && !flag[j])
		{
			flag[j] = true;
			DFS(row+1, num+1);
			flag[j] = false;
		}
	}
	DFS(row+1, num); 
	return;
}

int main()
{
	
	while(cin >> n >>k)
	{
        if(n==-1 && k==-1)  
            break;
		memset(chess, false, sizeof(chess));
		memset(flag, false, sizeof(flag));
		int i,j;
		char ch;
		exist = 0;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				cin >> ch;
				if(ch == '#')
					chess[i][j] = true;
			}
			
		}
		DFS(1, 0);
		cout << exist << endl;
	}
	return 0;
}
