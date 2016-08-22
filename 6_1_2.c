#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10
#define Vertex int

Vertex Check[MaxVertexNum];		//用来判断顶点是否访问过 
	
typedef struct ENode *Edge;		//边 
struct ENode{
	Vertex V1;
	Vertex V2;
};

typedef struct GNode *MGraph;		//图的定义--邻接矩阵 
struct GNode{
	Vertex Nv;
	Vertex Ne;
	Vertex G[MaxVertexNum][MaxVertexNum];
};

typedef struct VNode *PtrToVNode;	//存入队列的数据结构 
struct VNode{
	Vertex Data;
	PtrToVNode Next;
};

typedef struct QNode *Queue;		//队列 
struct QNode{
	PtrToVNode Front;
	PtrToVNode Rear;
};

MGraph CreateGraph(int);
MGraph BuildGraph(MGraph ,int);
void Insert(MGraph, Edge);
void InitializeArray(int);
void PrintUnion(MGraph);
void Visited(Vertex);
void TraverseBFS(MGraph ,Vertex);
Queue CreateQueue();
void EnQueue(Queue, Vertex);
int IsEmpty(Queue);
Vertex DeleteQueue(Queue);

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

//建立空图，每个数据设为0 
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

//建立完整的图--邻接矩阵表示法 
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

//将边插入图中（将数据放入图），这里是无向图 
void Insert(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->V2;
	Graph->G[E->V2][E->V1] = E->V1;
}

//初始化用来判断是否访问过的数组 
void InitializeArray(int N)
{
	int i;
	
	for(i = 0; i < N; i++)
		Check[i] = 0;
}

//第一次遍历的顶点设为访问过， 并输出 
void Visited(Vertex V)
{
	Check[V] = 1;
	printf("%d ", V);
}

//打印连通集 
void PrintUnion(MGraph Graph)
{
	int i;
	
	//遍历0到N-1的未访问过的顶点 
	for(i = 0; i < Graph->Nv; i++){
		if(!Check[i]){
			printf("{ ");
			TraverseBFS(Graph ,i);
			printf("}\n");
		}
	}
}

//广度优先搜索 
void TraverseBFS(MGraph Graph ,Vertex V)
{
	Vertex D, W;
	
	Queue Q = CreateQueue();
	Visited(V);
	EnQueue(Q, V);
	
	while(!IsEmpty(Q)){
		D = DeleteQueue(Q);
		for(W = 0; W < Graph->Nv; W++){
			//顶点W没有被访问过， ***并且W和V能构成一条边*** 
			if(!Check[W] && Graph->G[D][W]){
				Visited(W);
				EnQueue(Q, W);
			}
		}
	}
	free(Q->Front);
	free(Q);
}

//创建一个空队列，头尾指针指向队列首位元素之前的位置
//并且当且仅当 头尾指针相等时， 队列为空 
Queue CreateQueue()
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	//创建一个队列首位元素位置之前的结点
	//队列首尾指针同时指向它 
	PtrToVNode S = (PtrToVNode)malloc(sizeof(struct VNode));
	S->Data = -1;
	S->Next = NULL;
	Q->Front = Q->Rear = S;
	
	return Q;
}

void EnQueue(Queue Q, Vertex V)
{
	//入队时，头指针不动，尾指针向后挪一位 
	PtrToVNode S = (PtrToVNode)malloc(sizeof(struct VNode));
	S->Data = V;
	S->Next = NULL;
	Q->Rear->Next = S;
	Q->Rear = Q->Rear->Next;
}

//判断队列是否为空 
int IsEmpty(Queue Q) 
{
	return Q->Rear == Q->Front;
}

//删除队列的首元素 ， 并返回其值 
Vertex DeleteQueue(Queue Q)
{
	Vertex D;
	PtrToVNode Temp;
 
	D = Q->Front->Next->Data;	//头指针的下一位才是首元素 
	Temp = Q->Front;
	Q->Front = Q->Front->Next;	 //头指针往后挪， ****记住首元素是头指针的next的位置 *** 
	free(Temp);
	
	return D;
}
