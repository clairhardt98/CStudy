#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//
//void addSpace(char*, char*, int);
//char* getWordAddr(char*, char*);
//int main()
//{
//	char str[80] = "I am a boy. I'm happy!";
//	char targetWord[80] = "";
//	printf("Target word : ");
//	gets(targetWord);
//
//	char myWord[80] = "";
//
//	printf("%s -> ",targetWord);
//	gets(myWord);
//
//	char* targetWordAddr = getWordAddr(str, targetWord);
//	if (targetWordAddr != NULL)
//		printf("target word %s's address : %p\n", targetWord, targetWordAddr);
//	else
//	{
//		printf("no target word found\n");
//		return 0;
//	}
//
//	addSpace(str, targetWordAddr, strlen(myWord) - strlen(targetWord));
//
//	for(int i = 0; i < strlen(myWord);i++)
//	{
//		*(targetWordAddr + i) = *(myWord + i);
//	}
//
//	printf("result : ");
//	puts(str);
//
//}
//
//char* getWordAddr(char* str, char*targetWord)
//{
//	int matchedWord = 0;
//	for (int i = 0; i < strlen(str); i++)
//	{
//		char* temp = str + i;
//		if (*temp == *targetWord)
//		{
//			for (int j = 1; j < strlen(targetWord); j++)
//			{
//				if (*(temp + j) != *(targetWord + j))
//				{
//					matchedWord = 0;
//					break;
//				}
//				matchedWord++;
//			}
//			if (matchedWord == strlen(targetWord) - 1)
//			{
//				return (temp);
//			}
//		}
//	}
//	return NULL;
//}
////b������ strlen(girl) - boy��ŭ�� �� ĭ �Է�
////Ȯ�� �� ���� ���� ��ġ���� girl�Է�
//
//void addSpace(char* str, char* pstr, int n)
//{
//	int dist = pstr - str;
//	if (n >= 0)
//	{
//		for (int i = strlen(str); i > dist; i--)
//		{
//			str[i + n] = str[i];
//		}
//	}
//	else
//	{
//		for (int i = dist; i < strlen(str); i++)
//		{
//			str[i] = str[i - n];
//		}
//	}
//}

int a;
//void assign10();
//void assign20();
//int main()
//{
//	printf("�Լ� ȣ�� �� a �� : %d\n", a);
//	assign10();
//	assign20();
//
//	printf("�Լ� ȣ�� �� a �� : %d\n",a);
//
//	return 0;
//}
//
//void assign10()
//{
//	a = 10;
//}
//
//void assign20()
//{
//	int a;
//	a = 20;
//}

void auto_func();
void static_func();

int main()
{
	int i;
	static int a = 0;

	printf("�Ϲ� ���������� ����� �Լ�\n");
	for (i = 0; i < 3; i++)
	{
		auto_func();
	}

	printf("���� ���������� ����� �Լ�\n");
	for (i = 0; i < 3; i++)
	{
		static_func();
	}

	return 0;
}

void auto_func()
{
	auto int a = 0;

	a++;
	printf("%d\n", a);
}

void static_func()
{

	a++;
	printf("%d\n", a);
}