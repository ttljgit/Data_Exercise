//��bug 
#include <stdio.h>
#include <stdlib.h>
#define ElementType int

typedef struct Node * Tree;
struct Node{
	ElementType Element;
	Tree Left;
	Tree Right;
	int Height;
};

Tree BuildTree(int);
Tree Insert(Tree, int);
Tree SingleLeftRotation(Tree);
Tree SingleRightRotation(Tree);
Tree DoubleLeftRightRotation(Tree);
Tree DoubleRightLeftRotation(Tree);
void PrintRoot(Tree);
int Max(int, int);
int GetHeight(Tree);

int main()
{
	int N;
	Tree AVLTree;
	
	scanf("%d", &N);
	AVLTree = BuildTree(N);
	PrintRoot(AVLTree);
	
	return 	0;
}

Tree BuildTree(int N)
{
	int i, data;
	Tree T;
	
	for(i = 0; i < N; i++){
		scanf("%d", &data);
		T = Insert(T, data);
	}	

	return T;
}

//��data����AVL���֣������ص������AVL�� 
Tree Insert(Tree T, int data)
{
	//����һ���µĽ�� 
	if(!T){
		T = (Tree)malloc(sizeof(struct Node));
		T->Element = data;
		T->Left = NULL;
		T->Right = NULL;
		T->Height = 0;
	}
	// ����T�������� 
	else if(data < T->Element){
		T->Left = Insert(T->Left, data);
		if(GetHeight(T->Left) - GetHeight(T->Right) == 2){
			if(data < T->Left->Element)
				T = SingleLeftRotation(T);
			else
				T = DoubleLeftRightRotation(T);	
		}
	}
	//����T�������� 
	else if(data > T->Element){
		T->Right = Insert(T->Right, data);
		if(GetHeight(T->Left) - GetHeight(T->Right) == -2){
			if(data > T->Right->Element)
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);	
		}
	}	
	//�������� 
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	
	return T;
}

//LL LR RR Rl��ת ��ͼ������ �ܺ����� 
Tree SingleLeftRotation(Tree A)
{
	Tree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) +1;
	
	return B;
}

Tree SingleRightRotation(Tree A)
{
	Tree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(A->Height, GetHeight(B->Right)) + 1;
	
	return B;
}

Tree DoubleLeftRightRotation(Tree A)
{
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}

Tree DoubleRightLeftRotation(Tree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}

void PrintRoot(Tree T)
{
	printf("%d", T->Element);
}

//�ȽϺ��� 
int Max(int a, int b)
{
	return a >= b ? a : b;
}

//���ߺ�������Ϊ�ս��ʱ������-1 
int GetHeight(Tree T)
{
	if(T == NULL)
		return -1;
	else
		return T->Height;
}
