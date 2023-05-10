#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int arr[10][10];

int main()
{
	int N;
	scanf("%d", &N);

	int cnt = 1;

	int idx = 0;
	int dir = 0;

	int a = 1;
	while (idx < N*2 - 1)
	{
		if (idx < N)
		{
			if (!dir)
			{
				for (int i = 0; i < idx + 1; i++)
				{
					arr[idx - i][i] = cnt;
					cnt++;
				}
			}
			else
			{
				for (int i = 0; i < idx + 1; i++)
				{
					arr[i][idx - i] = cnt;
					cnt++;
				}
			}
			
		}
		else
		{
			if (dir)
			{
				for(int i = a;i<=idx-a;i++)
				{
					arr[i][idx-i] = cnt;
					cnt++;
				}
			}
			else
			{
				for (int i = a; i <= idx-a; i++)
				{
					arr[idx-i][i] = cnt;
					cnt++;
				}
			}
			a++;
		}

		idx++;
		if (dir)
			dir = 0;
		else
			dir = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++ )
			printf("%3d", arr[i][j]);
		printf("\n");
	}
}

//0,0				idx 0	dir = 0
//0,1 1,0			idx 1	dir = 1
//2,0 1,1 0,2		idx 2
//3,0 2,1 1,2 0,3	idx 3
//3,1 2,2 1,3		idx 4
//2,3 3,2
//4,4


