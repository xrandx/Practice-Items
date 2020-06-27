#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string.h>


using namespace std;

#define null -1
typedef struct tag_btree
{
	int left, right, value;
} btree, *btreeptr;

const int maxn = 100;


btree t[maxn];

int BuildTree(int &length)
{
	int n;
	int i;
	char l,r;
	scanf("%d", &n);
	length = n;
	int check[n];
	memset(check, 0, sizeof(check));
	for(i=0; i<n; i++)
	{
		scanf("\n%c %c", &l, &r);
		if(l == '-')
			t[i].left = null;
		else
		{
			t[i].left = l - '0';
			check[t[i].left] = 1;
		}
		if(r == '-')
			t[i].right = null;
		else
		{
			t[i].right = r - '0';
			check[t[i].right] = 1;
		}
		if(t[i].left == null && t[i].right == null)
			t[i].value = 1;
		else
			t[i].value = 0;
	}
	for(i=0; i<n; i++)
	{
		if(!check[i])
			break;
	}
	return i;
}

queue< int > q;

void GetDepth(int node, int length)
{
	//printf("%d ", node);
	int flag = 1;
	while(!q.empty())
	{
		node = q.front();
		if(t[node].value)
		{
			if(flag)
			{
				printf("%d", node);
				flag = 0;
			}
			else
			{
				printf(" %d", node);
			}
		}
		q.pop();
		if(t[node].left != null)
			q.push(t[node].left);
		if(t[node].right != null)
			q.push(t[node].right);
	}

}

int main()
{

	int r;
	int length;
	r = BuildTree(length);
	if(t[r].left == null || t[r].right == null)
		t[r].value == 1;
	int node = 0;
	q.push(r);
	GetDepth(node, length);
	printf("\n");
}
