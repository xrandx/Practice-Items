#include <stdlib.h>
#include <stdio.h>
#define null -1

typedef struct taglinkedlist
{
	int Address , data, Next;
	struct taglinkedlist *next;
} linkedlist, *listptr;

typedef struct taghead
{
	int address, nodesum, k;
	listptr hlink, tlink;
} head;


int main()
{
	head h;
	scanf("%d %d %d", &h.address, &h.nodesum, &h.k);
	listptr L = (listptr)malloc((h.nodesum + 1) * sizeof(linkedlist));
	L[0].next = NULL;
	h.hlink = h.tlink = NULL;
	for(int i = 1; i <= h.nodesum; i++)
	{
		scanf("\n%d %d %d", &L[i].Address, &L[i].data, &L[i].Next);
	}
	for(int i = 1; i <= h.nodesum; i++)
	{
		if(L[i].Next == null)
		{
			L[i].next = NULL;
			h.tlink = &L[i];
		}
		if(L[i].Address == h.address)
		{
			h.hlink = &L[i];
			L[0].next = &L[i];
		}
		for(int j = 1; j <= h.nodesum; j++)
		{
			if(L[i].Next == L[j].Address && L[i].Address != L[j].Address)
			{
				L[i].next = &L[j];
				break;
			}
		}
	}

	listptr curr, heck, tmp, p;
	if(L[0].next == NULL)
	{
		return 0;
	}
	if(L[0].next->next == NULL)
	{
		printf("%05d %d -1\n", (L[0].next)->Address, (L[0].next)->data );
		return 0;
	}
	if(h.k != h.nodesum)
	{
		//p = h.hlink;

		heck = L[0].next;
		curr = heck->next;
		heck->next = NULL;
		for(int i = 0; i < h.k - 1 ; i++)
		{
			tmp = curr->next;
			curr->next = heck;
			heck = curr;
			curr = tmp;
		}
		h.hlink->next = curr;
		L[0].next = heck;
	}
	else
	{
		heck = L[0].next;
		curr = heck->next;
		heck->next = NULL;
		while(curr)
		{
			tmp = curr->next;
			curr->next = heck;
			heck = curr;
			curr = tmp;
		}
		L[0].next = heck;
	}
	
	p = L[0].next;
	while(1)
	{
		if(p->next)
		{
			printf("%05d %d %05d\n", p->Address, p->data, p->next->Address);
			p = p->next;
		}
		else
		{
			printf("%05d %d -1\n", p->Address, p->data );
			break;
		}
	}
	return 0;






}
