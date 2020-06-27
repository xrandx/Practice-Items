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
typedef int Patharc[MAXVEX];		/*用于存储最短路径下标的数组*/
typedef int ShortPathTable[MAXVEX];		/*用于存储到各点最短路径的权值和*/
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable_Floyd[MAXVEX][MAXVEX];
using namespace std;

/*邻接矩阵方式建立图*/
class MGraph{
public:
VertexType vexs[MAXVEX];
EdgeType arc[MAXVEX][MAXVEX];
int numVertexes,numEdges;
};

/*建立无向网图的邻接矩阵表示*/
void CreateMGraph(MGraph *G)
{
int i,j,k,w;
cout<<"输入顶点数和边数："<<endl;
cin>>G->numVertexes>>G->numEdges;
cin.clear();
cout<<"输入顶点信息："<<endl;
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
cout<<"输入边（vi,vj）上的下标i，下标j和权w:"<<endl;
cin>>i>>j>>w;
cin.clear();
G->arc[i][j]=w;
cout<<w<<endl;
G->arc[j][i]=G->arc[i][j];
}
}
/* Dijkstra算法，求有向网G的V0顶点到其余顶点V最短路径P[V]及带权长度D[V]*/
/*P[V]的值为前驱顶点下标，D[V]表示V0到V的最短路径长度和*/
void ShortestPath_Dijkstra(MGraph G, int V0, int P[], int D[])
{
//cout<<"here_1!\n";
int v,w,k,min;
int final[MAXVEX];
for(v = 0; v<G.numVertexes; v++)//初始化
{
//cout<<"here_3!\n";
final[v] = 0;
(D)[v] = G.arc[V0][v];//放置权值
for(w=0;w<G.numVertexes;w++)
if(D[w]<INFINITY)
(P)[w] = V0;
}
(D)[V0] = 0;//到自身的距离为0
final[V0] = 1;//表示这个点已经找过了
//cout<<"here_2!\n";
/*开始主循环，每次求得V0到某个V顶点的最短路径*/
for(v=1; v<G.numVertexes; v++)
{
//cout<<"here_7!\n";
min = INFINITY;
for(w=0; w<G.numVertexes; w++)
{
if(!final[w] && (D)[w]<min)
{
k = w;
min = (D)[w];//更新最短距离
}
}
//cout<<"here_9!\n";
if(min<INFINITY)
final[k] = 1;//
else
break;
//cout<<"here_11!\n";
for (w=0; w<G.numVertexes; w++)		/*修正当前最短路径及距离*/
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
cout<<"V"<<V0<<"节点到其余个节点的最短路径为："<<endl;
for (w=0; w<G.numVertexes; w++)	
{
if(w!=V0)
cout<<(D)[w]<<"  ";
}
cout<<endl;
cout<<"V"<<V0<<"节点到其余个节点的最短路径的前驱节点为："<<endl;
for (w=0; w<G.numVertexes; w++)	
{
if(w!=V0)
cout<<"V"<<(P)[w]<<"  ";
}
cout<<endl;
}
/*Floyd算法，求网图G中各顶点V到其余顶点W最短路径P[V][W]及带权长度D[V][W]*/
void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable_Floyd *D)
{
int v,w,k;
for(v=0; v<G.numVertexes; ++v)	/*初始化D与P*/
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

for(v=0; v<G.numVertexes; ++v)	/*输出显示最短路径*/
{
for(w=v+1; w<G.numVertexes; w++)
{
cout<<"V"<<v<<"-V"<<w<<"的最短距离为："<<(*D)[v][w]<<endl;
k = (*P)[v][w];
cout<<"路径为：V"<<v;
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
/***********Floyd算法结束************/
int main()
{
MGraph G;
int  p[100]={0};
int  q[100]={0};
int a[100][100];
int b[100][100];
CreateMGraph(&G);
int n;
cout<<"请输入起点:";
cin>>n;
ShortestPath_Dijkstra(G,n,p,q);
ShortestPath_Floyd(G,&a,&b);
return 0;
