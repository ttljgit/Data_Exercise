//算法4 在线处理

#include <stdio.h>

int MaxSubqueueSum(int A[], int N)
{
	int ThisSum = 0;
	int MaxSum = 0;
	int i;
	
	for(i = 0; i < N; i++){
		ThisSum += A[i];		//向右累加 
		if(ThisSum > MaxSum)
			MaxSum = ThisSum;	//发现更大和则更新当前结果 
		else if (ThisSum < 0)	//如果当前子列和为负 
			ThisSum = 0;		//则不可能使后面的部分和增大，抛弃之 
	}
	
	return MaxSum;
} 

	
int main()
{
	int result = 0;
	int N, i, Num;
	int A[N];
	scanf("%d",&N);
	
	for(i = 0; i < N; i++){
		scanf("%d",&Num);
		A[i] = Num;
	}

	result = MaxSubqueueSum(A, N);
	printf("%d", result);
	
	return 0;
}
