#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10
#define Vertex int

Vertex Check[MaxVertexNum];

typedef struct ENode *Edge;
struct ENode{
	Vertex V1;
	Vertex V2;
};

typedef struct GNode *MGraph;
struct GNode{
	Vertex Nv;
	Vertex Ne;
	Vertex G[MaxVertexNum][MaxVertexNum];
};

MGraph CreateGraph(int);
MGraph BuildGraph(MGraph ,int);
void Insert(MGraph, Edge);
void InitializeArray(int);
void PrintUnion(MGraph);
void Visited(Vertex);
void TraverseDFS(MGraph,Vertex);

int main()
{
	int N, E;
	MGraph Graph;
	
	scanf("%d %d", &N, &E);
	Graph = CreateGraph(N);
	Graph = BuildGraph(Graph ,E);
	InitializeArray(N);
	PrintUnion(Graph);
}

MGraph CreateGraph(int N)
{
	int i, j;
	
	MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = N;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			Graph->G[i][j] = 0;
	
	return Graph;		
}

MGraph BuildGraph(MGraph Graph,int edge)
{
	int i;
	
	Edge E = (Edge)malloc(sizeof(struct ENode));
	for(i = 0; i < edge; i++){
		scanf("%d %d", &E->V1, &E->V2);
		Insert(Graph, E);
	}
	
	return Graph;
}

void Insert(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->V2;
	Graph->G[E->V2][E->V1] = E->V1;
}

void InitializeArray(int N)
{
	int i;
	
	for(i = 0; i < N; i++)
		Check[i] = 0;
}

void Visited(Vertex V)
{
	Check[V] = 1;
}

void PrintUnion(MGraph Graph)
{
	int i;
	
	for(i = 0; i < Graph->Nv; i++){
		if(!Check[i]){
			printf("{ ");
			TraverseDFS(Graph ,i);
			printf("}\n");
		}
	}
}

void TraverseDFS(MGraph Graph ,Vertex V)
{	
	int i;
	
	Visited(V);
	printf("%d ", V);
	
	for(i = 0; i < Graph->Nv; i++){
		if(Graph->G[V][i] && !Check[i]){
			TraverseDFS(Graph, i);
		}
	}
}
