// Maximum Subsequence Sum
#include <stdio.h>

void MaxSubqueueSum(int A[], int N)
{
	int ThisSum = 0;
	int MaxSum = 0;
	int i, k;
	int begin, end;
	int Flag = 0;
	
	for(i = 0; i < N; i++){
		ThisSum += A[i];
		if(ThisSum > MaxSum){
			MaxSum = ThisSum;
			k = i;		//����յ��λ�� 
		}
		else if(ThisSum < 0){
			ThisSum = 0;
		}	
	}
	//�ж�����յ��λ�� 
	end = A[k];
	for(; k > 0 && A[k] > 0; k--)
		begin = A[k];	
	printf("%d %d %d",MaxSum, begin, end);
}

int main()
{
	int N, i, Num;
	scanf("%d",&N);
	int A[N];
	
	for(i = 0; i < N; i++){
		scanf("%d",&Num);
		A[i] = Num;
	}
	MaxSubqueueSum(A, N);
	
	return 0;
}
