#include <stdio.h>

void MaxSubqueueSum(int A[], int N)
{
	int ThisSum = 0;
	int MaxSum = 0;
	int i, k;
	int begin, end;
	
	for(i = 0; i < N; i++){
		ThisSum += A[i];	//子列和 
		//如果本次累加的总和超过历史最大总和，则更新 
		if(ThisSum > MaxSum){
			MaxSum = ThisSum;
			k = i;		//标记终点的位置 
		}
		//如果子列和小于0，则令其为0，没必要再累加 
		else if(ThisSum < 0){
			ThisSum = 0;
		}	
	}
	//判断起点终点的位置 
	end = A[k];
	for(; k > 0 && A[k] > 0; k--)
		begin = A[k];	//起点肯定要大于0 
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
