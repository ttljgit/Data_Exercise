//有bug 
#include <stdio.h>

int MaxSubqueueSum(int A[], int N)
{
	int ThisSum = 0;
	int MaxSum = 0;
	int i, j;
	
	for(i = 0; i < N; i++){		//i是子列左端位置 
		ThisSum = 0;			//ThisSum是A[i]到A[j]的子列和 
		for(j = i; j < N; j++){	// j是子列右端位置 
			ThisSum += A[j];
			//对于相同的i，不同的j，只要在j-1此循环的基础上累加1项即可 
			if(ThisSum > MaxSum)
				MaxSum = ThisSum;	//如果新的子列和更大则更新 
		}
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
