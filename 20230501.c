#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*unsigned int m, n;

	scanf("%d%d", &m, &n);

	unsigned int idx = 1;

	while (1)
	{
		if (idx % m == 0 || idx % n == 0)
			printf("%d ", idx);

		if (idx > 100)	break;

		idx++;
	}*/

	/*int n;
	scanf("%d", &n);

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("* ");
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = n - i; j > 0; --j)
			printf("  ");
		for (int k = 0; k < i; ++k)
			printf("* ");

		printf("\n");
	}*/

	/*unsigned int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j || i + j == N - 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}*/

	/*unsigned int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n ;j++)
		{
			if (i == j || i + j == n - 1)
			{
				printf("* ");
			}
			else if (i + j < n - 1 && i > j)
			{
				printf("* ");

			}
			else if (i + j > n - 1 && j > i)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}

		}
		printf("\n");
	}*/

	unsigned int n;

	const int COL = 3;

	scanf("%d", &n);

	printf("              ±¸ ±¸ ´Ü               \n");

	for (int i = 2; i <= n; i += COL)
	{
		printf("--------------------------------------\n");

		for (int j = 1; j < 10; j++)
		{
			for (int k = i; k < i + COL; k++)
			{
				if (k <= n)
					printf("%2d * %d = %3d ", k, j, k * j);
			}
			printf("\n");
		}
	}

	return 0;
}