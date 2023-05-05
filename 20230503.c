#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int InputFunc();
//void OutputFunc(int N);
//
//int main()
//{
//	unsigned int N = InputFunc();
//	OutputFunc(N);
//	
//	return 0;
//	
//}
//int InputFunc()
//{
//	int N;
//
//	printf("2 이상의 정수를 입력하세요 : ");
//	scanf("%d", &N);
//
//	return N;
//}
//
//void OutputFunc(int N)
//{
//	int isPrime = 1;
//	int printCnt = 0;
//	for (int i = 2; i <= N; i++)
//	{
//		isPrime = 1;
//		for (int j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				isPrime = 0;
//				break;
//			}
//		}
//		if (isPrime)
//		{
//			printCnt += 1;
//			printf("%3d ", i);
//			if (printCnt % 5 == 0)
//				printf("\n");
//		}
//	}
//}
//Q2

	//int n;
	//scanf("%d", &n);

	//for (int i = 0; i <= 9; i++)
	//{
	//	for (int j = 0; j <= 9; j++)
	//	{
	//		/*int tempSum = (10 * i + j) + (10 * j + i);
	//		int digit_1 = tempSum % 10;
	//		int digit_10 = tempSum / 10;

	//		if (digit_1 == digit_10 && digit_1 == n)
	//		{
	//			printf("A = %d, Z = %d\n", i, j);
	//		}*/
	//		if(i + j == n)
	//			printf("A = %d, Z = %d\n", i, j);

	//	}
	//}


//Q3

//int abs(int n);
//
//int main()
//{
//	int N;
//	printf("종료하려면 0을 입력하세요.\n");
//
//	while (1)
//	{
//		printf("정수 입력 : ");
//		scanf("%d", &N);
//		if (N == 0) break;
//
//
//		printf("절대값은 : %d\n",abs(N));
//	}
//	
//}
//
//int abs(int n)
//{
//	return (n < 0) ? -n : n;
//}

//int rec_func_sum(int n);
//int rec_func_fact(int n);
//
//int main()
//{
//	int n;
//	printf("n을 입력하세요 : ");
//	scanf("%d", &n);
//	int a = rec_func_sum(n);
//	printf("1부터 %d까지의 합 : %d\n", n, a);
//	printf("%d! : %d\n", n, rec_func_fact(n));
//}
//
//int rec_func_sum(int n)
//{
//	if (n == 1) return n;
//	return n += rec_func_sum(n - 1);
//}
//
//int rec_func_fact(int n)
//{
//	if (n == 2) return n;
//	return n *= rec_func_fact(n - 1);
//}

//Q6
//달팽이 한 마리가 한 달이 지나면 성체, 다시 한 달이 지나면 새끼 낳음
//새로 태어난 달팽이도 한 달이 지나면 성체, 다시 한 달이 지나면 새끼 낳음
//달팽이가 매 달 새끼를 낳으면 1년 후 전체 달팽이의 수?
//1마리 -> 1달 후 성체, 2달 후 새끼, 3달 후 새끼, 4달 후 새끼 ... 12달 후 새끼
//11마리 낳음
//2번째 는 9마리
//3번재는 7마리 

//int snail(int n);
//
//int main()
//{
//	const int month = 12;
//	printf("%d개월 후 달팽이의 개체수 : %d\n",month, snail(month));
//	
//}
//
//int snail(int n)
//{
//	if (n < 2) return 1;
//	return snail(n - 1) + snail(n - 2);
//}

//Q3
//원하는 연산 선택

int sum(int, int);
int sub(int, int);
int mul(int, int);
float div(int, int);

int main()
{
	int op;
	while (1)
	{
		printf("원하는 연산을 선택하시오 : \n");
		printf("(1. 덧셈, 2. 뺄셈, 3. 곱셈, 4. 나눗셈, 0. 종료)\n");
		
		scanf("%d", &op);
		if (!op) break;
		int a, b;
		printf("두 정수를 입력하시오 : ");
		scanf("%d%d", &a, &b);
		switch (op)
		{
		case 1:
			printf("결과는 %d 입니다.\n", sum(a, b));
			break;
		case 2:
			printf("결과는 %d 입니다.\n", sub(a, b));
			break;
		case 3:
			printf("결과는 %d 입니다.\n", mul(a, b));
			break;
		case 4:
			printf("결과는 %.2f 입니다.\n", div(a, b));
			break;
		default:
			printf("다시 입력하세요.\n");
			break;
		}
	}

}

int sum(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
float div(int a, int b)
{
	return (float)a / (float)b;
}