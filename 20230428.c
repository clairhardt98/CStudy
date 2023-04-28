#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*int i = 10;

	double d = 10.111;

	int i2 = (int)d;

	double d2 = (double)i2;


	printf("i : %d\n", i);
	printf("d : %.3f\n", d);
	printf("i2 : %d\n", i2);
	printf("d2 : %.3f\n", d2);*/

	/*int a = 20, b = 3;

	double res;

	res = ((double)a) / ((double)b);
	printf("a = %d, b = %d\n",a, b);
	printf("res : %.1f\n", res);

	a = (int)res;
	printf("(int)res : %d\n", a);*/

	/*int a = 10, b = 20;

	int res = 2;

	a += 20;
	res *= b + 10;

	printf("a = %d, b = %d\n", a, b);
	printf("res = %d\n", res);*/

	/*int a = 10, b = 20;

	int res;
	res = (++a, ++b);

	printf("res : %d\n", res);*/

	/*int a = 10, b = 20, res;

	res = (a > b) ? a : b;

	printf("res : %d\n", res);*/

	//정수 3개 입력

	/*int a, b, c = 0;

	scanf("%d%d%d", &a, &b, &c);

	int temp = (a > b) ? a : b;

	int max = (temp > c) ? temp : c;

	printf("max : %d\n", max);*/

	/*int a = 10;
	int b = 12;

	printf("a & b : %d\n", a & b);
	printf("a ^ b : %d\n", a ^ b);
	printf("a | b : %d\n", a | b);
	printf("~a    : %d\n", ~a);
	printf("a << 1: %d\n", a << 1);
	printf("a >> 2: %d\n", a >> 2);*/

	//int a = 20;
	//int b = 0;

	//if (a > b)
	//	b = a;

	//printf("a : %d, b : %d\n", a, b);

	/*int a = 10;

	if (a >= 0)
	{
		a = 1;

	}
	else
	{
		a = -1;
	}

	printf("a : %d\n", a);*/

	/*int a = 0, b = 0;

	if (a > 0)
	{
		b = 1;
	}
	else if (a == 0)
	{
		b = 2;
	}
	else
	{
		b = 3;
	}

	printf("b : %d\n", b);*/

	/*int a, b;

	scanf("%d%d", &a, &b);

	int iRes = a - b;

	if (iRes < 0)
	{
		iRes = -iRes;
	}

	printf("case1) result : %d\n", iRes);

	printf("case2) result : %d\n", (iRes < 0) ? -iRes : iRes);*/


	//int rank = 2, m = 0;

	//scanf("%d", &rank);

	//switch (rank)
	//{
	//case 1 :
	//	m = 300;
	//	//break;
	//case 2:
	//	m = 200;
	//	break;
	//case 3:
	//	m = 100;
	//	break;
	//default:
	//	m = 10;
	//	break;
	//}

	//printf("m : %d\n", m);

	// 90이상 A 80이상 B 70이상 c 60이상 d 그 미만 F

	/*int iKorscore;
	int iEngscore;
	int iMatscore;

	printf("국어, 영어, 수학 성적을 입력하세요:\n");
	scanf("%d", &iKorscore);
	scanf("%d", &iEngscore);
	scanf("%d", &iMatscore);

	const int iAvgscore = (iKorscore + iEngscore + iMatscore) / 3;

	if (iAvgscore >= 90)
	{
		printf("A\n");
	}
	else if (iAvgscore >= 80)
	{
		printf("B\n");
	}
	else if (iAvgscore >= 70)
	{
		printf("C\n");
	}
	else if (iAvgscore >= 60)
	{
		printf("D\n");
	}
	else
	{
		printf("F\n");
	}*/

	/*int a = 1;

	while (a < 10)
	{
		printf("%d \n", a);
		a *= 2;
	}

	for (a = 1; a < 10; a *= 2)
	{
		printf("%d \n", a);

	}*/

	/*unsigned int n;

	scanf("%d", &n);

	int fact = 1;
	for (int i = n; i > 0; i--)
	{
		fact *= i;
	}

	printf("n! is %d\n", fact);
	int a = 1;
	
	func(a);
	
	printf("%d", a);*/

	/*int a, b;
	
	scanf("%d%d", &a, &b);

	if (a > b)
	{
		int temp = b;
		b = a;
		a = temp;
	}

	int sum = a;

	for (int i = a; i < b; ++i)
	{
		sum += i + 1;
	}

	printf("%d\n", sum);*/

	/*unsigned int M, N;

	scanf("%d%d", &M, &N);

	unsigned int iRes = 0;
	for (int i = 0; i < N; ++i)
	{
		iRes += M;
		printf("%d ", iRes);
	}
	int a;*/

	int iSum = 0;
	int temp;
	do
	{
		scanf("%d", &temp);
		iSum += temp;
	} while (temp != 0);
	
	printf("sum : %d\n", iSum);
	return 0;
}
