#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<stdlib.h>


//문자열을 입력받아 역으로 출력하는 프로그램 작성
//I am happy -> happy am i
//메모리 할당, 내용 복사 연습
int main()
{
	while (1)
	{
		char* str = (char*)malloc(100 * sizeof(char));
		gets(str);
		if (!strcmp(str, "quit")) return 0;
		int len = strlen(str);

		int wordcnt = 0;

		for (int i = 0; i < len + 1; i++)//단어 개수 체크
		{
			if (str[i] == ' ' || str[i] == '\0')
			{
				wordcnt++;
			}
		}

		char** words = (char*)malloc(wordcnt * sizeof(char*));//단어 개수만큼의 행을 갖는 2차원 char 배열


		int wordidx = 0;//단어 idx

		int wordlen = -1;//단어의 길이

		for (int i = 0; i < len + 1; i++)
		{
			wordlen++;
			if (str[i] == ' ' || str[i] == '\0')
			{
				words[wordidx] = (char*)malloc((wordlen + 1) * sizeof(char));

				for (int j = i - wordlen; j < i; j++)
				{
					words[wordidx][j-i+wordlen] = str[j];
				}
				words[wordidx][wordlen] = '\0';
				wordlen = 0;
				wordidx++;
				i++;
			}
		}
		free(str);

		for (int i = wordidx; i > 0; i--)
		{
			printf("%s ", words[i - 1]);
		}
		for (int i = 0; i < wordidx; i++)
		{
			free(words[i]);
		}
		printf("\n");
		free(words);
	}
	
	
}