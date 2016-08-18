//有bug 
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

//将data放入AVL树种，并返回调整后的AVL树 
Tree Insert(Tree T, int data)
{
	//创建一个新的结点 
	if(!T){
		T = (Tree)malloc(sizeof(struct Node));
		T->Element = data;
		T->Left = NULL;
		T->Right = NULL;
		T->Height = 0;
	}
	// 插入T的左子树 
	else if(data < T->Element){
		T->Left = Insert(T->Left, data);
		if(GetHeight(T->Left) - GetHeight(T->Right) == 2){
			if(data < T->Left->Element)
				T = SingleLeftRotation(T);
			else
				T = DoubleLeftRightRotation(T);	
		}
	}
	//插入T的右子树 
	else if(data > T->Element){
		T->Right = Insert(T->Right, data);
		if(GetHeight(T->Left) - GetHeight(T->Right) == -2){
			if(data > T->Right->Element)
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);	
		}
	}	
	//更新树高 
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	
	return T;
}

//LL LR RR Rl旋转 画图辅助看 很好理解的 
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

//比较函数 
int Max(int a, int b)
{
	return a >= b ? a : b;
}

//树高函数，当为空结点时候，树高-1 
int GetHeight(Tree T)
{
	if(T == NULL)
		return -1;
	else
		return T->Height;
}
