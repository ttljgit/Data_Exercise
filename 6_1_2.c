#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10
#define Vertex int

Vertex Check[MaxVertexNum];		//�����ж϶����Ƿ���ʹ� 
	
typedef struct ENode *Edge;		//�� 
struct ENode{
	Vertex V1;
	Vertex V2;
};

typedef struct GNode *MGraph;		//ͼ�Ķ���--�ڽӾ��� 
struct GNode{
	Vertex Nv;
	Vertex Ne;
	Vertex G[MaxVertexNum][MaxVertexNum];
};

typedef struct VNode *PtrToVNode;	//������е����ݽṹ 
struct VNode{
	Vertex Data;
	PtrToVNode Next;
};

typedef struct QNode *Queue;		//���� 
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

//������ͼ��ÿ��������Ϊ0 
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

//����������ͼ--�ڽӾ����ʾ�� 
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

//���߲���ͼ�У������ݷ���ͼ��������������ͼ 
void Insert(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->V2;
	Graph->G[E->V2][E->V1] = E->V1;
}

//��ʼ�������ж��Ƿ���ʹ������� 
void InitializeArray(int N)
{
	int i;
	
	for(i = 0; i < N; i++)
		Check[i] = 0;
}

//��һ�α����Ķ�����Ϊ���ʹ��� ����� 
void Visited(Vertex V)
{
	Check[V] = 1;
	printf("%d ", V);
}

//��ӡ��ͨ�� 
void PrintUnion(MGraph Graph)
{
	int i;
	
	//����0��N-1��δ���ʹ��Ķ��� 
	for(i = 0; i < Graph->Nv; i++){
		if(!Check[i]){
			printf("{ ");
			TraverseBFS(Graph ,i);
			printf("}\n");
		}
	}
}

//����������� 
void TraverseBFS(MGraph Graph ,Vertex V)
{
	Vertex D, W;
	
	Queue Q = CreateQueue();
	Visited(V);
	EnQueue(Q, V);
	
	while(!IsEmpty(Q)){
		D = DeleteQueue(Q);
		for(W = 0; W < Graph->Nv; W++){
			//����Wû�б����ʹ��� ***����W��V�ܹ���һ����*** 
			if(!Check[W] && Graph->G[D][W]){
				Visited(W);
				EnQueue(Q, W);
			}
		}
	}
	free(Q->Front);
	free(Q);
}

//����һ���ն��У�ͷβָ��ָ�������λԪ��֮ǰ��λ��
//���ҵ��ҽ��� ͷβָ�����ʱ�� ����Ϊ�� 
Queue CreateQueue()
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	//����һ��������λԪ��λ��֮ǰ�Ľ��
	//������βָ��ͬʱָ���� 
	PtrToVNode S = (PtrToVNode)malloc(sizeof(struct VNode));
	S->Data = -1;
	S->Next = NULL;
	Q->Front = Q->Rear = S;
	
	return Q;
}

void EnQueue(Queue Q, Vertex V)
{
	//���ʱ��ͷָ�벻����βָ�����Ųһλ 
	PtrToVNode S = (PtrToVNode)malloc(sizeof(struct VNode));
	S->Data = V;
	S->Next = NULL;
	Q->Rear->Next = S;
	Q->Rear = Q->Rear->Next;
}

//�ж϶����Ƿ�Ϊ�� 
int IsEmpty(Queue Q) 
{
	return Q->Rear == Q->Front;
}

//ɾ�����е���Ԫ�� �� ��������ֵ 
Vertex DeleteQueue(Queue Q)
{
	Vertex D;
	PtrToVNode Temp;
 
	D = Q->Front->Next->Data;	//ͷָ�����һλ������Ԫ�� 
	Temp = Q->Front;
	Q->Front = Q->Front->Next;	 //ͷָ������Ų�� ****��ס��Ԫ����ͷָ���next��λ�� *** 
	free(Temp);
	
	return D;
}
