#include <stdio.h>
#define Tree int
#define Null -1
#define MAXSIZE 10

//结构数组 
struct Node{
	char Element;
	Tree Left;
	Tree Right;
}T1[MAXSIZE], T2[MAXSIZE];

Tree BuildTree(struct Node TreeNode[])
{
	int N, i;
	char ch, cl, cr;
	
	scanf("%d", &N);
	ch = getchar();
	
	int Check[N];

	for(i = 0; i < N; i++)
		Check[i] = 0;
	//处理左右子树	
	for(i = 0; i < N; i++){
		scanf("%c %c %c", &TreeNode[i].Element, &cl, &cr);
		ch = getchar();
		if(cl != '-'){
			TreeNode[i].Left = cl - '0';
			Check[TreeNode[i].Left] = 1;
		}
		else
			TreeNode[i].Left = Null;
		if(cr != '-'){
			TreeNode[i].Right = cr - '0';
			Check[TreeNode[i].Right] = 1;
		}
		else
			TreeNode[i].Right = Null;	
	}
	//无结点指向的结点则为 根结点 
	for(i = 0; i < N; i++)
		if(Check[i] == 0)
			break;
	
/* test;	
	printf("\n");
	for(i = 0; i < N; i++){
		printf("%d   ",Check[i]);
		printf("%c %d %d\n", TreeNode[i].Element, TreeNode[i].Left, TreeNode[i].Right);
	}
	printf("\n");
*/			
	return i;		
}

 //该函数只在此题MAXSIZE中有效，不能扩展到N 
int Judge(Tree R1, Tree R2)
{
	//两树都为空 
	if(R1 == Null && R2 == Null)
		return 1;
	//空树和非空树	
	if((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))
		return 0;
	//两树的根节点不一样	
	if(T1[R1].Element != T2[R2].Element)
		return 0;
	//若过两树的左子树都空，判断右子树是否一样	
	if(T1[R1].Left == Null && T2[R2].Left == Null)
		return Judge(T1[R1].Right, T2[R2].Right);
	//若两树的左子树不空，并且左子树的结点元素都一样，判断左右子树是否一样	
	if((T1[R1].Left != Null && T2[R2].Left != Null) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
		return Judge(T1[R1].Left, T2[R2].Left) && Judge(T1[R1].Right, T2[R2].Right);
	else
	//否则 判断两树是否同构 
		return Judge(T1[R1].Left, T2[R2].Right) && Judge(T1[R1].Right, T2[R2].Left);				
}

int main()
{
	Tree Root1, Root2;
	
	
	Root1 = BuildTree(T1);
	Root2 = BuildTree(T2);
	if(Judge(Root1, Root2))
		printf("Yes");
	else
		printf("No");
	
	return 0;
}
