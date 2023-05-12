#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//학생 수 입력받음
//메뉴 구성, 1 - 입력, 2 - 평균에 따라 정렬된 형태로 출력, 3 - 이름으로 해당 학생의 학점, 성적을 출력, 4. 종료
//번호 중복 불가능, 이름은 중복 가능, 이름 검색 시 먼저 찾은 것을 우선으로 출력, 메모리 동적할당 사용, 자기참조 구조체 최대한 활용, 입력, 출력, 검색은 각각 개별 함수로 구현

//CreateConsoleScreenBuffer
//GetAsyncKeyState
//
enum menu { INPUT = 1, OUTPUT, SEARCH,EXIT };
#define GRADE 3
struct student
{
	int stnum;
	char name[20];
	int kgrade;
	int egrade;
	int mgrade;
	int total;
	double avg;
	char grade;
};

typedef enum menu MENU;
typedef struct student Student;

void input(Student*, int);
void output(Student*, int);
void search(Student*,  int);

void swap(Student*, Student*);

char getGrade(double);
int stnumsearch(Student*,int, int);

int isNullArr = 1;

int main()
{
	int N;
	printf("총 학생 수 : ");
	scanf("%d", &N);

	Student* starr = (Student*)malloc(N * sizeof(Student));
	if (starr == NULL) exit(1);

	while (1)
	{
		int m;
		printf("\n메뉴 입력(1. 입력, 2. 출력, 3. 검색, 4. 종료) : ");
		scanf("%d", &m);
		if (m > 4 || m < 1)
		{
			printf("잘못된 입력입니다. 다시 시도하세요.\n");
			continue;
		}
		MENU menu;
		
		menu = m;
		
		switch (menu)
		{
		case INPUT:
			printf("\n");
			input(starr, N);
			isNullArr = 0;
			break;
		case OUTPUT:
			printf("\n");
			output(starr, N);
			break;
		case SEARCH:
			printf("\n");
			search(starr, N);
			break;
		case EXIT:
			free(starr);
			return 0;
			break;
		}
	}
}

int stnumsearch(Student* starr, int Stnum,int idx)
{
	for (int i = 0; i < idx; i++)
	{
		if (starr[i].stnum == Stnum)
			return 0;
	}
	return 1;
}

void input(Student* starr, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		printf("학번 : ");
		scanf("%d", &starr[i].stnum);
		if (!stnumsearch(starr, starr[i].stnum, i))
		{
			printf("중복된 학번이 있습니다. 다시 입력하세요\n");
			i--;
			continue;
		}
		printf("이름 : ");
		scanf("%s", &starr[i].name);
		printf("국어, 영어, 수학 점수 : ");

		scanf("%d %d %d",&starr[i].kgrade, &starr[i].egrade, &starr[i].mgrade);//성적들 입력
		
		starr[i].total = starr[i].kgrade + starr[i].egrade + starr[i].mgrade;
		starr[i].avg = (double)starr[i].total / GRADE;
		starr[i].grade = getGrade(starr[i].avg);
	}
}

void output(Student* starr, int size)
{
	if (isNullArr)
	{
		printf("입력받지 않았습니다. 입력을 먼저 해주세요.\n");
		return 0;
	}
	printf("   학번    이름    국어    영어    수학    총점    평균    학점\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (starr[i].avg < starr[j].avg)
				swap(&starr[i], &starr[j]);
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%7d	%7s	%7d	%7d	%7d	%7d	%7.1lf %7c\n",
			starr[i].stnum, starr[i].name, starr[i].kgrade, starr[i].egrade, starr[i].mgrade, starr[i].total, starr[i].avg, starr[i].grade);
	}
}

void search(Student* starr, int size)
{
	if (isNullArr)
	{
		printf("입력받지 않았습니다. 입력을 먼저 해주세요.\n");
		return 0;
	}

	char temp[20];

	getchar();
	printf("이름으로 검색합니다 : ");

	gets(temp);
	
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(temp,starr[i].name))
		{
			printf("\n   이름    학점    국어    영어    수학    총점\n");
			printf("%7s %7c %7d %7d %7d %7d\n", starr[i].name, starr[i].grade, starr[i].kgrade, starr[i].egrade, starr[i].mgrade, starr[i].total);
			return 0;
		}
	}
	printf("해당 이름의 학생이 없습니다.\n");
}

void swap(Student* left, Student* right)
{
	Student temp = *left;
	*left = *right;
	*right = temp;
}

char getGrade(double avg)
{
	if (avg >= 90)
		return 'A';
	else if (avg >= 80)
		return 'B';
	else if (avg >= 70)
		return 'C';
	else
		return 'F';
}
