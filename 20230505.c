#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int main()
{
	int length = 0;

	char ch;

	int max = 0;

	while (scanf("%c", &ch) != -1)
	{
		if (ch == '\n')
		{
			if (max < length)
				max = length;

			length = 0;
		}
		else length++;
	}
	printf("가장 긴 단어의 길이 : %d", max);
}

//void input_nums(int* lotto_nums, int size);
//void print_nums(int* lotto_nums, int size);
//
//int main()
//{
//	int lotto_nums[6];
//	int size = sizeof(lotto_nums) / sizeof(lotto_nums[0]);
//
//	input_nums(lotto_nums, size);
//	print_nums(lotto_nums, size);
//}
//
//void input_nums(int* lotto_nums, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("번호 입력 : ");
//		scanf("%d", lotto_nums + i);
//		for (int j = 0; j < i; j++)
//		{
//			if (lotto_nums[i] == lotto_nums[j])
//			{
//				printf("같은 번호가 있습니다!\n");
//				i--;
//				break;
//			}
//		}
//	}
//}
//void print_nums(int* lotto_nums, int size)
//{
//	printf("로또 번호 : ");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", lotto_nums[i]);
//	}
//}

//void input_ary(double* pa, int size);
//double find_max(double* pa, int size);
//void output_ary(int* pa, int size);
//
//int main()
//{
//	double ary[5];
//	double max;
//
//	int size = sizeof(ary) / sizeof(ary[0]);
//
//	input_ary(ary, size);
//	max = find_max(ary, size);
//	printf("배열의 최대값 : %.1lf\n", max);
//	output_ary(ary, size);
//}
//
//void input_ary(double* pa, int size)
//{
//	int i;
//
//	printf("% d개의 실수값 입력 : ", size);
//	for (i = 0; i < size; i++)
//	{
//		scanf("%lf", pa + i);
//	}
//}
//
//double find_max(double* pa, int size)
//{
//	double max;
//	int i;
//
//	max = pa[0];
//
//	for (int i = 1; i < size; i++)
//	{
//		if (pa[i] > max) max = pa[i];
//	}
//
//	return max;
//}
//
//void output_ary(double* pa, int size)
//{
//	printf("배열 : ");
//	for (int i = 0; i < size; i++)
//		printf("%.1lf ", pa[i]);
//	printf("\n");
//}

//int main()
//{
//	int ary1[5] = { 10,20,30,40,50 };
//	int ary2[7] = { 10,20,30,40,50,60,70 };
//
//	print_ary(ary1, 5);
//	printf("\n");
//	print_ary(ary2, 7);
//
//	return 0;
//}
//
//void print_ary(int* pa, int size)
//{
//	int i;
//
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", pa[i]);
//	}
//}

//Q3
//int main()
//{
//	int arr[6] = { 1,2,3,4,5,6 };
//	int* fPtr = arr;
//	int* bPtr = arr + 5;
//	for (int i = 0; i < 6/2; i++)
//	{
//		int temp = *fPtr;
//		*fPtr = *bPtr;
//		*bPtr = temp;
//
//		fPtr++;
//		bPtr--;
//	}
//
//	for (int i = 0; i < 6; i++)
//		printf("%d ", arr[i]);
//}

//Q4
//int main()
//{
//	char str[100];
//	gets(str);
//
//	int length = strlen(str);
//	char* fPtr = str;
//	char* bPtr = str + length - 1;
//
//	for (int i = 0; i < length / 2; i++)
//	{
//		char temp = *fPtr;
//		*fPtr = *bPtr;
//		*bPtr = temp;
//
//		fPtr++;
//		bPtr--;
//	}
//	puts(str);
//}




//int main()
//{
//	char str[50];
//
//	gets(str);
//
//	system("cls");
//
//	int length = strlen(str);
//	
//	*(str + length) = ' ';
//	*(str + length + 1) = '\0';
//	
//	while (1)
//	{
//		puts(str);
//		
//		Sleep(500);
//		system("cls");
//
//		char temp = *str;
//
//		//printf("temp = %c\n", temp);
//		for (int i = 1; i <= length; i++)
//		{
//			*(str + (i - 1)) = *(str + i);
//			if (i == length)
//			{
//				*(str + length) = temp;
//			}
//		}
//	}
//	return 0;
//}
