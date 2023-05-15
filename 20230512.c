#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//�л� �� �Է¹���
//�޴� ����, 1 - �Է�, 2 - ��տ� ���� ���ĵ� ���·� ���, 3 - �̸����� �ش� �л��� ����, ������ ���, 4. ����
//��ȣ �ߺ� �Ұ���, �̸��� �ߺ� ����, �̸� �˻� �� ���� ã�� ���� �켱���� ���, �޸� �����Ҵ� ���, �ڱ����� ����ü �ִ��� Ȱ��, �Է�, ���, �˻��� ���� ���� �Լ��� ����

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
	printf("�� �л� �� : ");
	scanf("%d", &N);

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
		//�� ��� �߰�
		Student* ptr;
		Student* newStudent = (Student*)malloc(sizeof(Student));
		newStudent->next = NULL;
		printf("�й� : ");
		scanf("%d", &newStudent->stnum);

		int flag = 0;//�ݺ��� Ż���� ���� flag

		for (ptr = Head; ptr; ptr = ptr->next)
		{
			if (ptr->stnum == newStudent->stnum)
			{
				printf("���� �й��� �����մϴ�. �ٽ� �Է��ϼ���.\n");
				free(newStudent);
				flag = 1;
				i--;
				break;
			}
		}
		if (flag) continue;

		printf("�̸� : ");
		scanf("%s", &newStudent->name);
		
		printf("����, ����, ���� ���� : ");

		scanf("%d %d %d", &newStudent->kgrade, &newStudent->egrade, &newStudent->mgrade);//������ �Է�

		//printf("�л� %s �Է¹���\n", newStudent->name);
		newStudent->total = newStudent->kgrade + newStudent->egrade + newStudent->mgrade;
		newStudent->avg = (double)newStudent->total / GRADE;
		newStudent->grade = getGrade(newStudent->avg);

		

		if (Head == NULL)//ù �л��̸�
		{
			Head = newStudent;
		}
		else
		{
			//���� �տ� �߰�
			if (Head->avg <= newStudent->avg)
			{
				newStudent->next = Head;
				Head = newStudent;
			}
			else//�߰��� �߰�
			{
				for (ptr = Head; ptr->next; ptr = ptr->next)//ptr->next�� null �� �ƴ� ����
				{
					
					if (ptr->avg > newStudent->avg && ptr->next->avg < newStudent->avg)//�߰��� ����� ��ġ ã��
					{
						newStudent->next = ptr->next;
						ptr->next = newStudent;
						break;
					}
				}
				ptr->next = newStudent;//�������� �߰�
			}
		}
	}
}

void output(int size)
{
	if (Head == NULL)
	{
		printf("�Է¹��� �ʾҽ��ϴ�. �Է��� ���� ���ּ���.\n");
		return 0;
	}

	Student* ptr;
	printf("   �й�    �̸�    ����    ����    ����    ����    ���    ����\n");
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
		printf("�Է¹��� �ʾҽ��ϴ�. �Է��� ���� ���ּ���.\n");
		return 0;
	}

	char temp[20];

	getchar();
	printf("�̸����� �˻��մϴ� : ");

	gets(temp);

	Student* ptr;

	for (ptr = Head;ptr;ptr = ptr->next)
	{
		if (!strcmp(temp,ptr->name))
		{
			printf("\n   �̸�    ����    ����    ����    ����    ����\n");
			printf("%7s %7c %7d %7d %7d %7d\n", ptr->name, ptr->grade, ptr->kgrade, ptr->egrade, ptr->mgrade, ptr->total);
			return 0;
		}
	}
	printf("�ش� �̸��� �л��� �����ϴ�.\n");
}

void deleteAll()
{
	Student* ptr = Head;
	
	while (ptr != NULL)
	{
		Student* nxt = ptr->next;
		//printf("�й� %d�� �л� ����\n", ptr->stnum);
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
