#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	FILE* fp;
	char str[20];
	int res;
	int length;
	int N;

	fp = fopen("99.txt", "w");
	if (fp == NULL) exit(1);

	for (int i = 2; i < 10; i++)
		for (int j = 1; j < 10; j++)
			fprintf(fp, "%2d X %2d = %2d\n", i, j, i * j);

	fclose(fp);
	fp = fopen("99.txt", "r+");
	res = fgets(str, sizeof(str), fp);
	//printf("str : %s\n", str);

	length = strlen(str);
	//printf("length : %d\n", length);

	printf("몇 단 출력 ? ");
	scanf("%d", &N);

	int startPos = (N - 2) * 9;

	for (int i = 0; i < 9; i++)
	{
		fseek(fp, (startPos + i) * (length + 1), SEEK_SET);
		res = fgets(str, sizeof(str), fp);
		printf(str);
	}
	fclose(fp);
}

	//2단이면 0, 3단이면 9번째 줄에서 시작
	//2*1 -> 0번째 idx
	//2*2 -> 0+13
//
//int main()
//{
//	char src[100];
//	char dest[100];
//
//	printf("원본 파일 : ");
//	scanf("%s", &src);
//	printf("대상 파일 : ");
//	scanf("%s", &dest);
//
//	FILE* fs, * fd;
//
//	fs = fopen(src,"rb");
//	if (fs == NULL) exit(1);
//
//	int N;
//
//	printf("몇 바이트씩 ? :");
//	scanf("%d", &N);
//
//	fseek(fs, 0, SEEK_END);
//	int size_s = ftell(fs);
//	fseek(fs, 0, SEEK_SET);
//	
//	
//	printf("파일의 사이즈 : %d\n", size_s);
//
//	int res = 1;
//	fd = fopen(dest, "wb");
//
//	int* file = (int*)malloc(N * sizeof(int));
//	int cnt = 0;
//	while (cnt <= size_s)
//	{
//		fread(file, sizeof(file), 1, fs);
//		fwrite(file, sizeof(file), 1, fd);
//		
//		printf("원본 파일 : %s\n", src);
//		printf("대상 파일 : %s\n", dest);
//		printf("진행도 : %.1lf%\n", 100 * (double)cnt / size_s);
//		cnt += N;
//		system("cls");
//	}
//	fclose(fs);
//	fclose(fd);
//}

