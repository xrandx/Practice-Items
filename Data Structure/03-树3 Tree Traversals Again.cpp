//03-?3 Tree Traversals Again
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <string.h>
#include <stdlib.h>
using namespace std;
typedef struct tag
{
	int num;
	struct tag *l, *r;
} node;
typedef node *rootptr;
queue < int > inq;

rootptr restore(int inorder[], int pre[], int inbegin, int inend, int prebegin)
{
	//从中序找根结点
	for(int root = inbegin; root <= inend; root++)
	{
		if(pre[prebegin] == inorder[root])
		{
			inq.push(root);
			break;
		}
	}
	if(!inq.empty())
	{
		rootptr p = (rootptr)malloc(sizeof(node));
		int root = inq.front();
		inq.pop();
		p->num = inorder[root];
		if(root == inbegin)
		{
			p->l = NULL;
		}
		else
		{
			p->l = restore(inorder, pre, inbegin, inq.front() - 1, prebegin + 1);
		}
		if(root == inend)
		{
			p->r = NULL;
		}
		else
		{
			p->r = restore(inorder, pre, inq.front() + 1, inend);
		}
		return p;
	}

}


int main()
{
	int n;
	char ch[4];
	int m;
	stack <int> s;
	cin >> n;
	int inorder[n];
	int pre[n];
	int j = 0;
	int k = 0;
	for(int i = 0; i < 2 * n; i++)
	{
		scanf("%s", &ch);
		if(!strcmp("Push", ch))
		{
			scanf("%d", &m);
			pre[k++] = m;
			s.push(m);
		}
		else if(!strcmp("Pop", ch))
		{
			inorder[j++] = s.top();
			s.pop();
		}
	}
	rootptr r = restore(inorder, pre, 0, n-1);

}

