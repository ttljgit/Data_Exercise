//��bug 
#include <stdio.h>

int MaxSubqueueSum(int A[], int N)
{
	int ThisSum = 0;
	int MaxSum = 0;
	int i, j;
	
	for(i = 0; i < N; i++){		//i���������λ�� 
		ThisSum = 0;			//ThisSum��A[i]��A[j]�����к� 
		for(j = i; j < N; j++){	// j�������Ҷ�λ�� 
			ThisSum += A[j];
			//������ͬ��i����ͬ��j��ֻҪ��j-1��ѭ���Ļ������ۼ�1��� 
			if(ThisSum > MaxSum)
				MaxSum = ThisSum;	//����µ����к͸�������� 
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
