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
//	printf("2 �̻��� ������ �Է��ϼ��� : ");
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
//	printf("�����Ϸ��� 0�� �Է��ϼ���.\n");
//
//	while (1)
//	{
//		printf("���� �Է� : ");
//		scanf("%d", &N);
//		if (N == 0) break;
//
//
//		printf("���밪�� : %d\n",abs(N));
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
//	printf("n�� �Է��ϼ��� : ");
//	scanf("%d", &n);
//	int a = rec_func_sum(n);
//	printf("1���� %d������ �� : %d\n", n, a);
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
//������ �� ������ �� ���� ������ ��ü, �ٽ� �� ���� ������ ���� ����
//���� �¾ �����̵� �� ���� ������ ��ü, �ٽ� �� ���� ������ ���� ����
//�����̰� �� �� ������ ������ 1�� �� ��ü �������� ��?
//1���� -> 1�� �� ��ü, 2�� �� ����, 3�� �� ����, 4�� �� ���� ... 12�� �� ����
//11���� ����
//2��° �� 9����
//3����� 7���� 

//int snail(int n);
//
//int main()
//{
//	const int month = 12;
//	printf("%d���� �� �������� ��ü�� : %d\n",month, snail(month));
//	
//}
//
//int snail(int n)
//{
//	if (n < 2) return 1;
//	return snail(n - 1) + snail(n - 2);
//}

//Q3
//���ϴ� ���� ����

int sum(int, int);
int sub(int, int);
int mul(int, int);
float div(int, int);

int main()
{
	int op;
	while (1)
	{
		printf("���ϴ� ������ �����Ͻÿ� : \n");
		printf("(1. ����, 2. ����, 3. ����, 4. ������, 0. ����)\n");
		
		scanf("%d", &op);
		if (!op) break;
		int a, b;
		printf("�� ������ �Է��Ͻÿ� : ");
		scanf("%d%d", &a, &b);
		switch (op)
		{
		case 1:
			printf("����� %d �Դϴ�.\n", sum(a, b));
			break;
		case 2:
			printf("����� %d �Դϴ�.\n", sub(a, b));
			break;
		case 3:
			printf("����� %d �Դϴ�.\n", mul(a, b));
			break;
		case 4:
			printf("����� %.2f �Դϴ�.\n", div(a, b));
			break;
		default:
			printf("�ٽ� �Է��ϼ���.\n");
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