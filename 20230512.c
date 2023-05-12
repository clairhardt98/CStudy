#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//�л� �� �Է¹���
//�޴� ����, 1 - �Է�, 2 - ��տ� ���� ���ĵ� ���·� ���, 3 - �̸����� �ش� �л��� ����, ������ ���, 4. ����
//��ȣ �ߺ� �Ұ���, �̸��� �ߺ� ����, �̸� �˻� �� ���� ã�� ���� �켱���� ���, �޸� �����Ҵ� ���, �ڱ����� ����ü �ִ��� Ȱ��, �Է�, ���, �˻��� ���� ���� �Լ��� ����

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
	printf("�� �л� �� : ");
	scanf("%d", &N);

	Student* starr = (Student*)malloc(N * sizeof(Student));
	if (starr == NULL) exit(1);

	while (1)
	{
		int m;
		printf("\n�޴� �Է�(1. �Է�, 2. ���, 3. �˻�, 4. ����) : ");
		scanf("%d", &m);
		if (m > 4 || m < 1)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
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
		printf("�й� : ");
		scanf("%d", &starr[i].stnum);
		if (!stnumsearch(starr, starr[i].stnum, i))
		{
			printf("�ߺ��� �й��� �ֽ��ϴ�. �ٽ� �Է��ϼ���\n");
			i--;
			continue;
		}
		printf("�̸� : ");
		scanf("%s", &starr[i].name);
		printf("����, ����, ���� ���� : ");

		scanf("%d %d %d",&starr[i].kgrade, &starr[i].egrade, &starr[i].mgrade);//������ �Է�
		
		starr[i].total = starr[i].kgrade + starr[i].egrade + starr[i].mgrade;
		starr[i].avg = (double)starr[i].total / GRADE;
		starr[i].grade = getGrade(starr[i].avg);
	}
}

void output(Student* starr, int size)
{
	if (isNullArr)
	{
		printf("�Է¹��� �ʾҽ��ϴ�. �Է��� ���� ���ּ���.\n");
		return 0;
	}
	printf("   �й�    �̸�    ����    ����    ����    ����    ���    ����\n");
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
		printf("�Է¹��� �ʾҽ��ϴ�. �Է��� ���� ���ּ���.\n");
		return 0;
	}

	char temp[20];

	getchar();
	printf("�̸����� �˻��մϴ� : ");

	gets(temp);
	
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(temp,starr[i].name))
		{
			printf("\n   �̸�    ����    ����    ����    ����    ����\n");
			printf("%7s %7c %7d %7d %7d %7d\n", starr[i].name, starr[i].grade, starr[i].kgrade, starr[i].egrade, starr[i].mgrade, starr[i].total);
			return 0;
		}
	}
	printf("�ش� �̸��� �л��� �����ϴ�.\n");
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
