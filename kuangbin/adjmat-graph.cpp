/* 20161506146 ���轣  */ 
/* Windows 10 / Dev C++ / VScode */
/*�ڽӾ����ͼ*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

const int INFINITY = 65535;
const int maxv = 100;
std::queue <int> q;
typedef struct matrix
{
	int Nv;
	int Ne;
	char data[maxv][2];
	int adjmat[maxv][maxv];
} adjmat, *adjmatptr;

typedef struct edge
{
	int v1,v2;
	int weight;
} edge;

adjmatptr createadjmat(int vertex)
{
	adjmatptr g = (adjmatptr)malloc(sizeof(adjmat));
	g->Nv = vertex;
	g->Ne = 0;
	for(int i = 0; i < g->Nv; i++)
	{
		for(int j = 0; j < g->Nv; j++)
		{
			g->adjmat[i][j] = INFINITY;
		}
	}
	return g;
}

void Insertadjmat(adjmatptr g, edge e)
{
	g->adjmat[e.v1][e.v2] = e.weight;
	g->adjmat[e.v2][e.v1] = e.weight;
	return;
}

void dfs(adjmatptr g, int v, int visit[])
{
	printf("%c%c\t", g->data[v][0], g->data[v][1]);
	visit[v] = 1;
	for(int i = 0; i < g->Nv; i++)
	{
		if(g->adjmat[v][i] !=  INFINITY)
		{
			if(!visit[i])
				dfs(g, i, visit);
		}
	}
	return;
}

void bfs(adjmatptr g, int visit[])
{
	q.push(0);
	visit[0] = 1; 
	while(!q.empty())
	{
		int v;
		v = q.front();
		q.pop();
		printf("%c%c\t", g->data[v][0], g->data[v][1]);
		for(int i = 0; i < g->Nv; i++)
		{
			if(g->adjmat[v][i] !=  INFINITY)
			{
				if(!visit[i])
				{
					q.push(i);
					visit[i] = 1;
				}
			}
		}
	}
	return;
}


int vis(adjmatptr g, int visit[])
{
	for(int i = 0; i < g->Nv; i++)
	{
		if(!visit[i])
			return 0;
	}
	return 1;
}
int main()
{
	int adjv;
	adjmatptr adjg;
	printf("����ͼ��������");
	scanf("%d", &adjv);
	adjg = createadjmat(adjv);
	printf("����ͼ������");
	scanf("%d", &adjg->Ne);
	printf("��������˵�����(�����ַ�)\n");
	for(int i =0; i < adjg->Nv; i++)
	{
		printf("�����%d����",i+1);
		scanf("%s", adjg->data[i]);
	}
	printf("����������߶˵�\n");
	for(int i = 0; i < adjg->Ne; i++)
	{
		edge e;
		printf("����һ�Զ˵㣺");
		scanf("%d %d", &e.v1, &e.v2);
		Insertadjmat(adjg, e);
	}
	int visit[adjg->Nv];
	memset(visit, 0, sizeof(visit));
	printf("��ȱ���Ϊ��\n");
	dfs(adjg, 0, visit);
	memset(visit, 0, sizeof(visit));

	printf("\n��ȱ���Ϊ��\n");
	
	bfs(adjg, visit);
	return 0;
}
