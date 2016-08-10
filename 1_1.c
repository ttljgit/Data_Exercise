//有bug 

#include <stdio.h>
int MaxSubqueueSum(int A[], int N)
{
	int MaxSum = 0;
	int ThisSum = 0; 
	int i, j, k;
	
	for(i = 0; i <N; i++){		//i是子列左端 
		for(j = i; j < N; j++){		//j是子列右端 
			ThisSum = 0;		//ThisSum是从A[i]到A[j]的子列和 
			for(k = i; k <= j; k++){
				ThisSum += A[k];
			}
			if(ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}
int main()
{
	int N, i, Num;
	int A[N];
	scanf("%d",&N);
	
	for(i = 0; i < N; i++){
		scanf("%d",&Num);
		A[i] = Num;
	}

	printf("%d",MaxSubqueueSum(A, N));
	
	return 0;
}
