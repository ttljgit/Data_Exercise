//�㷨4 ���ߴ���

#include <stdio.h>

int MaxSubqueueSum(int A[], int N)
{
	int ThisSum = 0;
	int MaxSum = 0;
	int i;
	
	for(i = 0; i < N; i++){
		ThisSum += A[i];		//�����ۼ� 
		if(ThisSum > MaxSum)
			MaxSum = ThisSum;	//���ָ��������µ�ǰ��� 
		else if (ThisSum < 0)	//�����ǰ���к�Ϊ�� 
			ThisSum = 0;		//�򲻿���ʹ����Ĳ��ֺ���������֮ 
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
