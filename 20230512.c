#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//학생 수 입력받음
//메뉴 구성, 1 - 입력, 2 - 평균에 따라 정렬된 형태로 출력, 3 - 이름으로 해당 학생의 학점, 성적을 출력, 4. 종료
//번호 중복 불가능, 이름은 중복 가능, 이름 검색 시 먼저 찾은 것을 우선으로 출력, 메모리 동적할당 사용, 자기참조 구조체 최대한 활용, 입력, 출력, 검색은 각각 개별 함수로 구현

//CreateConsoleScreenBuffer
//GetAsyncKeyState

enum menu
{
	INPUT = 1, OUTPUT, SEARCH, EXIT
};
#define GRADE 3

typedef struct student Student;
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

	Student* next;
};

typedef enum menu MENU;


void input(int);
void output(int);
void search(int);

void deleteAll();

char getGrade(double);
int stnumsearch(Student*, int, int);

Student* Head = NULL;

int main()
{
	int N;
	printf("총 학생 수 : ");
	scanf("%d", &N);

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
			input(N);
			break;
		case OUTPUT:
			printf("\n");
			output(N);
			break;
		case SEARCH:
			printf("\n");
			search(N);
			break;
		case EXIT:
			deleteAll();
			return 0;
			break;
		}
	}
}

int stnumsearch(Student* starr, int Stnum, int idx)
{
	for (int i = 0; i < idx; i++)
	{
		if (starr[i].stnum == Stnum)
			return 0;
	}
	return 1;
}

void input(int size)
{

	for (int i = 0; i < size; i++)
	{
		//새 노드 추가
		Student* ptr;
		Student* newStudent = (Student*)malloc(sizeof(Student));
		newStudent->next = NULL;
		printf("학번 : ");
		scanf("%d", &newStudent->stnum);

		int flag = 0;//반복문 탈출을 위한 flag

		for (ptr = Head; ptr; ptr = ptr->next)
		{
			if (ptr->stnum == newStudent->stnum)
			{
				printf("같은 학번이 존재합니다. 다시 입력하세요.\n");
				free(newStudent);
				flag = 1;
				i--;
				break;
			}
		}
		if (flag) continue;

		printf("이름 : ");
		scanf("%s", &newStudent->name);
		
		printf("국어, 영어, 수학 점수 : ");

		scanf("%d %d %d", &newStudent->kgrade, &newStudent->egrade, &newStudent->mgrade);//성적들 입력

		//printf("학생 %s 입력받음\n", newStudent->name);
		newStudent->total = newStudent->kgrade + newStudent->egrade + newStudent->mgrade;
		newStudent->avg = (double)newStudent->total / GRADE;
		newStudent->grade = getGrade(newStudent->avg);

		

		if (Head == NULL)//첫 학생이면
		{
			Head = newStudent;
		}
		else
		{
			//가장 앞에 추가
			if (Head->avg <= newStudent->avg)
			{
				newStudent->next = Head;
				Head = newStudent;
			}
			else//중간에 추가
			{
				for (ptr = Head; ptr->next; ptr = ptr->next)//ptr->next가 null 이 아닌 동안
				{
					
					if (ptr->avg > newStudent->avg && ptr->next->avg < newStudent->avg)//중간에 끼어들어갈 위치 찾기
					{
						newStudent->next = ptr->next;
						ptr->next = newStudent;
						break;
					}
				}
				ptr->next = newStudent;//마지막에 추가
			}
		}
	}
}

void output(int size)
{
	if (Head == NULL)
	{
		printf("입력받지 않았습니다. 입력을 먼저 해주세요.\n");
		return 0;
	}

	Student* ptr;
	printf("   학번    이름    국어    영어    수학    총점    평균    학점\n");
	for (ptr = Head;ptr;ptr=ptr->next)
	{
		printf("%7d	%7s	%7d	%7d	%7d	%7d	%7.1lf %7c\n",
			ptr->stnum, ptr->name, ptr->kgrade, ptr->egrade, ptr->mgrade, ptr->total, ptr->avg, ptr->grade);
	}
}

void search(int size)
{
	if (Head == NULL)
	{
		printf("입력받지 않았습니다. 입력을 먼저 해주세요.\n");
		return 0;
	}

	char temp[20];

	getchar();
	printf("이름으로 검색합니다 : ");

	gets(temp);

	Student* ptr;

	for (ptr = Head;ptr;ptr = ptr->next)
	{
		if (!strcmp(temp,ptr->name))
		{
			printf("\n   이름    학점    국어    영어    수학    총점\n");
			printf("%7s %7c %7d %7d %7d %7d\n", ptr->name, ptr->grade, ptr->kgrade, ptr->egrade, ptr->mgrade, ptr->total);
			return 0;
		}
	}
	printf("해당 이름의 학생이 없습니다.\n");
}

void deleteAll()
{
	Student* ptr = Head;
	
	while (ptr != NULL)
	{
		Student* nxt = ptr->next;
		//printf("학번 %d의 학생 삭제\n", ptr->stnum);
		free(ptr);
		ptr = nxt;
	}
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
