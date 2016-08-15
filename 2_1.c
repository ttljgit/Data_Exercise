//��bug δ��ɰ汾 
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
};

void Attach(int c, int e, Polynomial *pRear)
{
	Polynomial P;
	
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;		//����ǰ�����β�� 
	*pRear = P;				//��ǰ����Ϊ���һ�� 
}

Polynomial ReadPoly()
{
	Polynomial P, Rear, t;
	int c, e, N;
	
	scanf("%d",&N);
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while (N--){
		scanf("%d %d",&c, &e);
		Attach(c, e, &Rear);	//����ǰ��������ʽβ�� 
	}
	//ɾ����ʱ���ɵĿ�ͷ��� 
	t = P;
	P = P->link;
	free(t);
}

int Compare(int p1, int p2)
{
	if(p1 > p2)
		return 1;
	else if(p1 < p2)
		return -1;
	else
		return 0;		
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;
	while (P1 && P2){
		switch(Compare(P1->expon, P2->expon)){
			case 1:
					Attach(P1->coef, P1->expon, &rear);
					P1 =  P1->link;
					break;
			case -1:
					Attach(P2->coef, P2->expon, &rear);
					P2 = P2->link;
					break;
			case 0:
					//���ϵ����Ϊ0 
					sum = P1->coef + P2->coef;
					if(sum)
						Attach(sum, P1->expon, &rear);
						P1 = P1->link;
						P2 = P2->link;
						break;				
		}
	}
	//��δ�����������һ������ʽ�����нڵ����θ��Ƶ��������ʽ�� 
	while(P1){
		Attach(P1->coef, P1->expon, &rear);
		P1 = P1->link;
	}
	while(P2){
		Attach(P1->coef, P2->expon, &rear);
		P2 = P2->link;
	}
	
	rear->link = NULL;
	temp = front;
	front = front->link;	//��frontָ��������ʽ�ĵ�һ����0�� 
	free(temp);
	
	return front;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, t1, t2, t;
	int c, e;
	
	if(!P1 || !P2)
		return NULL;
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	Rear = P;
	//����P1�ĵ�һ�����P2��������õ� P 
	while(t2){
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1){
		t2 = P2;
		Rear = P;
		while (t2){
			c = t1->coef * t1->coef;
			e = t1->expon + t1->expon;
			while (Rear->link && Rear->link->expon > e)
				Rear = Rear->link;
			if(Rear->link && Rear->link->expon == e){
				//�ж�ϵ���Ƿ�Ϊ0 
				if(Rear->link->coef + c)
					Rear->link->coef += c;
				else{ 
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}			
			}
			else{ 
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
				Rear = t;
			}	
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = P;
	P = P->link;
	free(t2);
	
	return P;
}

void PrintPoly(Polynomial P)
{
	int flag = 0;
	
	if(!P){
		printf("0 0\n");
		return ;
	}
	while(P){
		if(!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", P->coef, P->expon);		
		P = P->link;
	}
	printf("\n");
}

int main()
{
	Polynomial P1, P2, PMult, PAdd;
	
	P1 = ReadPoly();
	P2 = ReadPoly();
	PMult = Mult(P1, P2);
	PrintPoly(PMult);
	PAdd = Add(P1, P2);
	PrintPoly(PAdd);
	
	return 0;
}
