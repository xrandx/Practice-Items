#include<iostream>
//#include"LinkQueue.h"
#define MAXVEX 100
#define MAXEDGE 100
#define INFINITY 65535
#define TRUE 1
#define FALSE 0
typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;
typedef int Patharc[MAXVEX];		/*���ڴ洢���·���±������*/
typedef int ShortPathTable[MAXVEX];		/*���ڴ洢���������·����Ȩֵ��*/
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable_Floyd[MAXVEX][MAXVEX];
using namespace std;

/*�ڽӾ���ʽ����ͼ*/
class MGraph{
public:
VertexType vexs[MAXVEX];
EdgeType arc[MAXVEX][MAXVEX];
int numVertexes,numEdges;
};

/*����������ͼ���ڽӾ����ʾ*/
void CreateMGraph(MGraph *G)
{
int i,j,k,w;
cout<<"���붥�����ͱ�����"<<endl;
cin>>G->numVertexes>>G->numEdges;
cin.clear();
cout<<"���붥����Ϣ��"<<endl;
for(i=0;i<G->numVertexes;i++)
{
cin>>G->vexs[i];
cin.clear();
}
for(i=0;i<G->numVertexes;i++)
for(j=0;j<G->numVertexes;j++)
{
if (i==j)
G->arc[i][j]=0;
else
G->arc[i][j]=INFINITY;
}
for(k=0;k<G->numEdges;k++)
{
cout<<"����ߣ�vi,vj���ϵ��±�i���±�j��Ȩw:"<<endl;
cin>>i>>j>>w;
cin.clear();
G->arc[i][j]=w;
cout<<w<<endl;
G->arc[j][i]=G->arc[i][j];
}
}
/* Dijkstra�㷨����������G��V0���㵽���ඥ��V���·��P[V]����Ȩ����D[V]*/
/*P[V]��ֵΪǰ�������±꣬D[V]��ʾV0��V�����·�����Ⱥ�*/
void ShortestPath_Dijkstra(MGraph G, int V0, int P[], int D[])
{
//cout<<"here_1!\n";
int v,w,k,min;
int final[MAXVEX];
for(v = 0; v<G.numVertexes; v++)//��ʼ��
{
//cout<<"here_3!\n";
final[v] = 0;
(D)[v] = G.arc[V0][v];//����Ȩֵ
for(w=0;w<G.numVertexes;w++)
if(D[w]<INFINITY)
(P)[w] = V0;
}
(D)[V0] = 0;//������ľ���Ϊ0
final[V0] = 1;//��ʾ������Ѿ��ҹ���
//cout<<"here_2!\n";
/*��ʼ��ѭ����ÿ�����V0��ĳ��V��������·��*/
for(v=1; v<G.numVertexes; v++)
{
//cout<<"here_7!\n";
min = INFINITY;
for(w=0; w<G.numVertexes; w++)
{
if(!final[w] && (D)[w]<min)
{
k = w;
min = (D)[w];//������̾���
}
}
//cout<<"here_9!\n";
if(min<INFINITY)
final[k] = 1;//
else
break;
//cout<<"here_11!\n";
for (w=0; w<G.numVertexes; w++)		/*������ǰ���·��������*/
{
//cout<<"here_10!\n";
if(!final[w] && (min+G.arc[k][w]<(D)[w]))
{
(D)[w] = min+G.arc[k][w];
printf("D[%d]=%d\n",w,D[w]);
(P)[w] = k;
}
}
}
cout<<"V"<<V0<<"�ڵ㵽������ڵ�����·��Ϊ��"<<endl;
for (w=0; w<G.numVertexes; w++)	
{
if(w!=V0)
cout<<(D)[w]<<"  ";
}
cout<<endl;
cout<<"V"<<V0<<"�ڵ㵽������ڵ�����·����ǰ���ڵ�Ϊ��"<<endl;
for (w=0; w<G.numVertexes; w++)	
{
if(w!=V0)
cout<<"V"<<(P)[w]<<"  ";
}
cout<<endl;
}
/*Floyd�㷨������ͼG�и�����V�����ඥ��W���·��P[V][W]����Ȩ����D[V][W]*/
void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable_Floyd *D)
{
int v,w,k;
for(v=0; v<G.numVertexes; ++v)	/*��ʼ��D��P*/
{
for(w=0; w<G.numVertexes; ++w)
{
(*D)[v][w] = G.arc[v][w];
(*P)[v][w] = w;
}
}
for(k=0; k<G.numVertexes; ++k)
{
for(v=0; v<G.numVertexes; ++v)
{
for(w=0; w<G.numVertexes; ++w)
{
if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
{
(*D)[v][w] = (*D)[v][k]+(*D)[k][w];
(*P)[v][w] = (*P)[v][k];
}
}
}
}

for(v=0; v<G.numVertexes; ++v)	/*�����ʾ���·��*/
{
for(w=v+1; w<G.numVertexes; w++)
{
cout<<"V"<<v<<"-V"<<w<<"����̾���Ϊ��"<<(*D)[v][w]<<endl;
k = (*P)[v][w];
cout<<"·��Ϊ��V"<<v;
while(k!=w)
{
cout<<" -> V"<<k;
k=(*P)[k][w];
}
cout<<" -> V"<<w<<endl;
}
cout<<endl;
}
}
/***********Floyd�㷨����************/
int main()
{
MGraph G;
int  p[100]={0};
int  q[100]={0};
int a[100][100];
int b[100][100];
CreateMGraph(&G);
int n;
cout<<"���������:";
cin>>n;
ShortestPath_Dijkstra(G,n,p,q);
ShortestPath_Floyd(G,&a,&b);
return 0;
