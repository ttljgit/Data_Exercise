#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define ElementType int 
#define Tree int 
#define Null -1

//结构数组存结点的数据 
typedef struct Node *PtrToNode;
struct Node{
	ElementType Element;
	Tree Left;
	Tree Right;
	struct Node *Next;
}TreeArray[MAXSIZE];

//队列的头尾指针，指向结点 
typedef struct QNode *Queue;
struct QNode{
	PtrToNode Front;
	PtrToNode Rear;
};


Tree BuildTree(int N)
{
	int i;
	char ch, cl, cr;
	int Check[N];
	
	//Check数组 当结点指向i，则i不是根结点 
	for(i = 0; i < N; i++)
		Check[i] = 0;
	
	for(i = 0; i < N; i++){
		scanf("%c %c", &cl, &cr);
		ch = getchar();				//有字符 读取回车 
		
		TreeArray[i].Element = i;	//按给定的顺序依次录入 
		//处理左子树 
		if(cl != '-'){
			TreeArray[i].Left = cl - '0';
			Check[TreeArray[i].Left] = 1;
		}
		else
			TreeArray[i].Left = Null;
		//处理右子树	 
		if(cr != '-'){
			TreeArray[i].Right = cr - '0';
			Check[TreeArray[i].Right] = -1;
		}	
		else
			TreeArray[i].Right = Null;
	}
//	test !!!	
//	for(i = 0; i < N; i++)
//		printf("%d %d %d\n", TreeArray[i].Element, TreeArray[i].Left, TreeArray[i].Right);
	//找出根结点 
	for(i = 0; i < N; i++)
		if(Check[i] == 0)
			break;
							
	return i;		
}

Queue CreateQueue(Tree Root)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	//创建队列，指向根节点 
	Q->Front = Q->Rear = &TreeArray[Root];
	
	return Q;
}


void PrintLeave(Queue Q, int N)
{
	int i;
	
	//最后一个节点肯定是树叶，单独写，可处理最后的空格 
	for(i = 1; i < N; i++){
		//如果节点没有子树，则为树叶 
		if(Q->Front->Left == -1 && Q->Front->Right == -1)
			printf("%d ", Q->Front->Element);
		//如果有左子树，加入队列，尾指针后挪	
		if(Q->Front->Left != -1){
			Q->Rear->Next = &TreeArray[Q->Front->Left];	
			Q->Rear = Q->Rear->Next;
		}
		if(Q->Front->Right != -1){
			Q->Rear->Next = &TreeArray[Q->Front->Right];
			Q->Rear = Q->Rear->Next;
		}
		//遍历左右子树后，首指针后挪 
		Q->Front = Q->Front->Next;
	}
	printf("%d", Q->Front->Element);
}

int main()
{
	int N;
	char ch;
	scanf("%d", &N);
	ch = getchar();
	
	Tree Root;
	Queue Q;
	
	Root = BuildTree(N);
	Q = CreateQueue(Root);
	PrintLeave(Q, N);
	
	return 0;
}
 
