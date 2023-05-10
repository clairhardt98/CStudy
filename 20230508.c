#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void lowChar(char* str, int length);

int main()
{

	char str1[80];
	char str2[80];
	char str3[80];

	printf("세 단어 입력 : ");

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);

	char tempStr1[80] = "";
	char tempStr2[80] = "";
	char tempStr3[80] = "";

	strcpy(tempStr1, str1);
	strcpy(tempStr2, str2);
	strcpy(tempStr3, str3);

	lowChar(tempStr1, strlen(tempStr1));
	lowChar(tempStr2, strlen(tempStr2));
	lowChar(tempStr3, strlen(tempStr3));

	char* first = str1;
	char* mid = str2;
	char* last = str3;

	if (strcmp(tempStr1, tempStr2) > 0)
	{
		if (strcmp(tempStr2, tempStr3) > 0)
		{
			first = str1;
			mid = str2;
			last = str3;
		}
		else
		{
			if (strcmp(tempStr1, tempStr3) > 0)
			{
				first = str1;
				mid = str3;
				last = str2;
			}
			else
			{
				first = str3;
				mid = str1;
				last = str2;
			}
		}
	}
	else if (strcmp(tempStr1, tempStr2) < 0)
	{
		if (strcmp(tempStr1, tempStr3) > 0)
		{
			first = str2;
			mid = str1;
			last = str3;
		}
		else
		{
			if (strcmp(tempStr2, tempStr3) > 0)
			{
				first = str2;
				mid = str3;
				last = str1;
			}
			else
			{
				first = str3;
				mid = str2;
				last = str1;
			}
		}
	}
	printf("%s %s %s\n", last, mid, first);
}


void lowChar(char* str, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 'A' && str[i] < 'Z')
			str[i] += 32;
	}
}
