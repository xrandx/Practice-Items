#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int n = 10000;
time_t begin, end;
double t; 

inline void random(int a[])
{
	srand(time(NULL));
	for(int i= 1; i <= n; i++)
	{
//		a[i] = rand() % n;
		a[i] = 10000 - i;
	}
}

inline void display(int a[])
{
	arr(a);
	for(int i = 1; i <= 10; i++)
	{
		cout << a[i] << "   ";
	}
	cout << "\n";
}

void Insertsort(int a[])
{
	int i, j;
	begin = clock();
	for(i = 2; i <= n; i++)
	{
		if(a[i] < a[i-1])
		{
			a[0] = a[i];
			a[i] = a[i-1];
			
			for( j = i - 2; j >= 1 && a[j] > a[0]; j--)
				a[j+1] = a[j];
			a[j+1] = a[0]; 
		}
	}
	end = clock();
	t = double(end - begin) / CLOCKS_PER_SEC;
	cout << "插入排序后前十项:\n";
	display(a);
	cout << "排序时间 ";
	cout << t << "s\n\n";
}

void BInsert(int a[])
{
	int low , high, m, j;
	begin = clock();
	for(int i = 2; i <= n; i++)
	{
		a[0] = a[i];
		low = 1; high = i - 1;
		while(low <= high)
		{
			m = (low + high) / 2;
			if(a[i] < a[m])
				high = m - 1;
			else low = m + 1;
		}
		for(j = i - 1; j >= high+1; j--)
			a[j+1] = a[j];
		a[high+1] = a[0];
	}
	end = clock();
	t = double(end - begin) / CLOCKS_PER_SEC;
	cout << "二分排序后前十项:\n";
	display(a);
	cout << "排序时间 ";
	cout << t << "s\n\n";
}

//void ShellSort(int a[])
//{
//	
//}



int main()
{
	int a[n + 6];
	random(a);
	Insertsort(a);
	random(a);
	BInsert(a);
	
	
}
