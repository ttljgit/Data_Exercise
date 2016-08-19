//�ѵ�ʵ�������飬 ��AVL�Ͷ�������������ʵ�� 

#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define Sentinel -10001 

typedef struct Node *MinHeap;
struct Node{
	ElementType *Data;	//���飬�������� 
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
	
	//��ӡ·��
	for(i = 0; i < M; i++){
		scanf("%d", &seat);
		printf("%d", Heap->Data[seat]);
		//��ӡ�丸���ֱ�����ڵ� 
		while(seat > 1){
			seat /= 2;	//���½�� 
			printf(" %d", Heap->Data[seat]);
		}
		printf("\n");
	}
}

//��������ΪN����С�� 
MinHeap CreateHeap(int N)
{
	MinHeap H = (MinHeap)malloc(sizeof(struct Node));
	H->Data = (ElementType *)malloc((N+1) * sizeof(ElementType));	//Ϊ���������㹻�ģ�N+1�����ռ� 
	H->Capacity = N;
	H->Size = 0;
	H->Data[0] = Sentinel;	//�ڱ�Ԫ��С�ڿ��ܳ��ֵ���Сֵ 
	
	return H;
}

//��Ԫ��һ�������룬 ��������С�ѵ���̬
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
	
	H->Size++;	//���¶ѵĴ�С
	//������ֵ�i��Ԫ��С�ڸ���㣬 ��ô�����Ҫ������ 
	for(i = H->Size; H->Data[i/2] > X; i /= 2)
		H->Data[i] = H->Data[i/2];
	H->Data[i] = X;	 //����i��Ԫ�ؽ�Сʱ�� ����������λ�� 
}

int IsFull(MinHeap H)
{
	return H->Capacity == H->Size;
}

