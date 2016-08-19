//堆的实现用数组， 比AVL和二叉搜索树容易实现 

#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define Sentinel -10001 

typedef struct Node *MinHeap;
struct Node{
	ElementType *Data;	//数组，存入数据 
	int Size;
	int Capacity;
};

MinHeap CreateHeap(int);
MinHeap BuildHeap(MinHeap, int);
void Insert(MinHeap, int);
int IsFulll(MinHeap);

int main()
{
	int N, M, i, seat;
	MinHeap Heap;
	
	scanf("%d %d", &N, &M);
	Heap = CreateHeap(N);
	Heap = BuildHeap(Heap, N);
	
	//打印路径
	for(i = 0; i < M; i++){
		scanf("%d", &seat);
		printf("%d", Heap->Data[seat]);
		//打印其父结点直至根节点 
		while(seat > 1){
			seat /= 2;	//更新结点 
			printf(" %d", Heap->Data[seat]);
		}
		printf("\n");
	}
}

//创建容量为N的最小堆 
MinHeap CreateHeap(int N)
{
	MinHeap H = (MinHeap)malloc(sizeof(struct Node));
	H->Data = (ElementType *)malloc((N+1) * sizeof(ElementType));	//为数组申请足够的（N+1个）空间 
	H->Capacity = N;
	H->Size = 0;
	H->Data[0] = Sentinel;	//哨兵元素小于可能出现的最小值 
	
	return H;
}

//将元素一个个插入， 并保持最小堆的形态
MinHeap BuildHeap(MinHeap H, int N)
{
	int i, X;
	
	for(i = 0; i < N; i++){
		scanf("%d", &X);
		Insert(H, X);
	}
	
	return H;
} 

void Insert(MinHeap H, int X)
{
	int i;
	
	if(IsFull(H)){
		printf("Can't Insert AnyMore");
		return ;
	}
	
	H->Size++;	//更新堆的大小
	//如果发现第i个元素小于父结点， 那么父结点要往下移 
	for(i = H->Size; H->Data[i/2] > X; i /= 2)
		H->Data[i] = H->Data[i/2];
	H->Data[i] = X;	 //当第i个元素较小时， 即所需插入的位置 
}

int IsFull(MinHeap H)
{
	return H->Capacity == H->Size;
}

