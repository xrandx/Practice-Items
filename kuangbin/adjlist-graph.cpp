/* 20161506146 ���轣  */ 
/* Windows 10 / Dev C++ / VScode */
/*�ڽӱ��ͼ*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
std::queue <int> q;
const int maxv = 100;
typedef struct edge
{
	int v1, v2;
} edge, *edgeptr;

typedef struct adjnode
{
	int adjv;
	struct adjnode *next;
	int w;
} adjnode, *adjnodeptr;


typedef struct vnode
{
	adjnodeptr firstedge;
	char data[2];
} adjlist[maxv];

typedef struct gnode
{
	int Nv;
	int Ne;
	adjlist adj;
} adjg, *adjgptr;

adjgptr createadjlist(int v)
{
	adjgptr g;
	g = (adjgptr)malloc(sizeof(adjg));
	g->Ne = 0;
	g->Nv = v;
	for(int i =0; i < g->Nv; i++)
	{
		g->adj[i].firstedge = NULL;
	}
	return g;
}

void Insertadjlist(adjgptr g, edge e)
{
	adjnodeptr tail, p;
	p = (adjnodeptr)malloc(sizeof(adjnode));
	
	p->next = NULL;
	p->adjv = e.v2;
	
	if(g->adj[e.v1].firstedge)
	{
		tail = g->adj[e.v1].firstedge;
		while(tail->next)
			tail = tail->next;
		tail->next = p;
	}
	else
	{
		g->adj[e.v1].firstedge = p;
	}
	
	
	p = (adjnodeptr)malloc(sizeof(adjnode));
	p->next = NULL;
	p->adjv = e.v1;
	
	if(g->adj[e.v2].firstedge)
	{
		tail = g->adj[e.v2].firstedge;
		while(tail->next)
			tail = tail->next;
		tail->next = p;
	}
	else
	{
		g->adj[e.v2].firstedge = p;
	}

	return;
}


void dfs(adjgptr g, int v, int visit[])
{
	adjnodeptr p;
	printf("%s\t", g->adj[v].data);
	visit[v] = 1;
	for(p = g->adj[v].firstedge; p; p = p->next)
	{
		if(!visit[p->adjv])
			dfs(g, p->adjv, visit);
	}
	return;
}

void bfs(adjgptr g, int visit[])
{
	q.push(0);
	visit[0] = 1; 
	while(!q.empty())
	{
		adjnodeptr p;
		int v = q.front();
		printf("%s\t", g->adj[v].data);
		q.pop();
		for(p = g->adj[v].firstedge; p; p = p->next)
		{
			if(!visit[p->adjv])
			{
				q.push(p->adjv);
				visit[p->adjv] = 1;
			}
		
		}
	}
}

int main()
{
	int adjv;
	adjgptr g;
	printf("����ͼ��������");
	scanf("%d", &adjv);
	g = createadjlist(adjv);
	printf("����ͼ������");
	scanf("%d", &g->Ne);
	printf("��������˵�����(�����ַ�)\n");
	for(int i =0; i < g->Nv; i++)
	{
		printf("�����%d����",i+1);
		scanf("%s",  g->adj[i].data);
	}
	printf("����������߶˵�\n");
	for(int i = 0; i < g->Ne; i++)
	{
		edge e;
		printf("����һ�Զ˵㣺");
		scanf("%d %d", &e.v1, &e.v2);
		Insertadjlist(g, e);
	}
	int visit[g->Nv];
	memset(visit, 0, sizeof(visit));
	printf("��ȱ���Ϊ��\n");
	dfs(g, 0, visit);
	
	memset(visit, 0, sizeof(visit));
	printf("\n��ȱ���Ϊ��\n");
	bfs(g, visit);
	
	return 0;
}
