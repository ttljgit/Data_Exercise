//��bug 

#include <stdio.h>
int MaxSubqueueSum(int A[], int N)
{
	int MaxSum = 0;
	int ThisSum = 0; 
	int i, j, k;
	
	for(i = 0; i <N; i++){		//i��������� 
		for(j = i; j < N; j++){		//j�������Ҷ� 
			ThisSum = 0;		//ThisSum�Ǵ�A[i]��A[j]�����к� 
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
