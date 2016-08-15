#include <stdio.h>
#include <stdlib.h>

typedef struct Node *pNode;
struct Node{
	int Address;
	int Data;
	int Next;
	pNode PNext;
};

pNode Match(int a, int d, int n)
{
	pNode P;
	 
	P = (pNode)malloc(sizeof(struct Node));
	P->Address = a;
	P->Data = d;
	P->Next = n;
	
	return P;
}

pNode CreateList(pNode Array[], int N)
{
	pNode front, rear;
	int i;
	
	front = (pNode)malloc(sizeof(struct Node));		//创建一个空的起始结点 
	rear = front;
	for(i = 1; i <= N; i++){
		rear->PNext = Array[i];
		rear = rear->PNext;
	}
	
	return front;
}

int choice(int K, int N)
{
	if(2 * K > N)
		return 1;	
	else 
		return 2;	
}

//情况1：前部分逆序，后部分正序 
void ReverseList_1(pNode List, int K, int N)
{
	pNode  old, fresh, temp;
	int cnt = 1;
	
	//fresh old temp三者关系画图理解，重新进行链表的排序 
	fresh = List->PNext;
	old = fresh->PNext;
	
	while (cnt < K){
		temp = old->PNext;
		old->PNext = fresh;
		fresh = old;
		old = temp;
		cnt++;			
	}
	List->PNext->PNext = old;	//将前部分和后部分进行粘合 
	
	for(cnt = 1; cnt < N; cnt++){
		printf("%05d %d %05d\n", fresh->Address, fresh->Data, fresh->PNext->Address);
		fresh = fresh->PNext;
	}
	printf("%05d %d -1\n", fresh->Address, fresh->Data);	//最后一项进行特殊处理 
	
}

//情况2：前部分逆序，后部分也逆序，注意cntd的次数 
void ReverseList_2(pNode List, int K, int N)
{
	pNode fresh_1, old, temp, fresh_2;
	int cnt = 1;
	
	fresh_1 = List->PNext;
	old = fresh_1->PNext;
	while (cnt < K){
		temp = old->PNext;
		old->PNext = fresh_1;
		fresh_1 = old;
		old = temp;
		cnt++;
	}
	//fresh_1是新的头结点 
	//分割成两部分 
	fresh_2 = old;
	old = fresh_2->PNext;
	cnt++;
	while (cnt < N){
		temp = old->PNext;
		old->PNext = fresh_2;
		fresh_2 = old;
		old = temp;
		cnt++;
	}
	List->PNext->PNext = fresh_2;	//粘合前后部分 
	
	for(cnt = 1; cnt < N; cnt++){
		printf("%05d %d %05d\n", fresh_1->Address, fresh_1->Data, fresh_1->PNext->Address);
		fresh_1 = fresh_1->PNext;
	}
	printf("%05d %d -1",fresh_1->Address, fresh_1->Data);
}

int main()
{
	int i, FirstAddress, N, K, Tag;
	int a, d, n;
	pNode P, List;
	
	//读入第一行数据 
	scanf("%d %d %d", &FirstAddress, &N, &K);
	pNode Array[N+1];	//指针数组， 每个元素指向结构 
	
	//将将每组数据按1 2 3 ...有序的放入数组中 
	for(i = 0; i < N; i++){
		scanf("%d %d %d", &a, &d, &n);
		Array[d] = Match(a, d, n);
	}
	 
	List = CreateList(Array, N);	//创建有序单链表 
	Tag = choice(K, N);
	switch(Tag){				//进行链表的逆序 
		case 1: ReverseList_1(List, K, N);
				break;
		case 2:	ReverseList_2(List, K, N);
				break;
	}
	
	return 0;	
	
}
