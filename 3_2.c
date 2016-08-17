#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define ElementType int 
#define Tree int 
#define Null -1

//�ṹ������������ 
typedef struct Node *PtrToNode;
struct Node{
	ElementType Element;
	Tree Left;
	Tree Right;
	struct Node *Next;
}TreeArray[MAXSIZE];

//���е�ͷβָ�룬ָ���� 
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
	
	//Check���� �����ָ��i����i���Ǹ���� 
	for(i = 0; i < N; i++)
		Check[i] = 0;
	
	for(i = 0; i < N; i++){
		scanf("%c %c", &cl, &cr);
		ch = getchar();				//���ַ� ��ȡ�س� 
		
		TreeArray[i].Element = i;	//��������˳������¼�� 
		//���������� 
		if(cl != '-'){
			TreeArray[i].Left = cl - '0';
			Check[TreeArray[i].Left] = 1;
		}
		else
			TreeArray[i].Left = Null;
		//����������	 
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
	//�ҳ������ 
	for(i = 0; i < N; i++)
		if(Check[i] == 0)
			break;
							
	return i;		
}

Queue CreateQueue(Tree Root)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	//�������У�ָ����ڵ� 
	Q->Front = Q->Rear = &TreeArray[Root];
	
	return Q;
}


void PrintLeave(Queue Q, int N)
{
	int i;
	
	//���һ���ڵ�϶�����Ҷ������д���ɴ������Ŀո� 
	for(i = 1; i < N; i++){
		//����ڵ�û����������Ϊ��Ҷ 
		if(Q->Front->Left == -1 && Q->Front->Right == -1)
			printf("%d ", Q->Front->Element);
		//�������������������У�βָ���Ų	
		if(Q->Front->Left != -1){
			Q->Rear->Next = &TreeArray[Q->Front->Left];	
			Q->Rear = Q->Rear->Next;
		}
		if(Q->Front->Right != -1){
			Q->Rear->Next = &TreeArray[Q->Front->Right];
			Q->Rear = Q->Rear->Next;
		}
		//����������������ָ���Ų 
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
 
