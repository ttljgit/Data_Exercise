#include <stdio.h>
#include <stdlib.h>
#define ElementType int

typedef struct Node *Tree;
struct Node{
	ElementType Element;
	Tree Left;
	Tree Right;
	int Flag;
};

Tree BuildTree(int);
Tree CreateNewNode(int);
Tree Insert(Tree, int);
int Judge(Tree, int);
int Check(Tree, int);
void Reset(Tree);
void FreeTree(Tree);

int main()
{
	int N, L, i;
	Tree T;
	
	scanf("%d", &N);
	while (N){
		scanf("%d", &L);
		int Result[L];
		T = BuildTree(N);
		
		for(i = 0; i < L; i++){
			Result[i] = Judge(T, N);
			Reset(T);
		}
		
		for(i = 0; i < L; i++){
			if(Result[i] == 1)
				printf("Yes\n");
			else
				printf("No\n");	
		}
		FreeTree(T);
		scanf("%d", &N);
	}
	return 0;
}

Tree BuildTree(int N)
{
	int i, data;
	Tree T;
	
	scanf("%d", &data);
	T = CreateNewNode(data);
	for(i = 1; i < N; i++){
		scanf("%d", &data);
		T = Insert(T, data);
	}
	
	return T;
}

Tree CreateNewNode(int data)
{
	Tree T = (Tree)malloc(sizeof(struct Node));
	T->Element = data;
	T->Left = NULL;
	T->Right = NULL;
	T->Flag = 0;
	
	return T;
}

Tree Insert(Tree T, int data)
{
	if(!T)
		T = CreateNewNode(data);
	else{
		if(data < T->Element)
			T->Left = Insert(T->Left, data);
		else if(data > T->Element)
			T->Right = Insert(T->Right, data);
	}
		
	return T;			
}

int Judge(Tree T, int N)
{
	int i, data;
	int flag = 1;
	
	scanf("%d", &data);
	if(data != T->Element)
		return 0;
	else
		T->Flag = 1;	
	
	//flag = 1代表正常 flag = 0 代表不匹配 
	for(i = 1; i < N; i++){
		scanf("%d", &data);
		flag = Check(T, data);
		if(!flag)
			break;
	}
	return flag;
}

//返回1当前结点代表匹配 
int Check(Tree T, int data)
{	
	if(T->Flag){
		if(data < T->Element)
			return Check(T->Left, data);
		else if(data > T->Element)
			return Check(T->Right, data);
		else
			return 0;	
	}
	else{
		if(data == T->Element){
			T->Flag = 1;
			return 1;
		}
		else
			return 0;
	}
				
}

void Reset(Tree T)
{
	if(T->Left)
		Reset(T->Left);
	if(T->Right)
		Reset(T->Right);
		
	T->Flag = 0;		
}

void FreeTree(Tree T)
{
	if(T->Left)
		FreeTree(T->Left);
	if(T->Right)
		FreeTree(T->Right);
	
	free(T);		
}
