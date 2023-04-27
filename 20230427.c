#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	//unsigned char alphabet;
	//unsigned int year, month;
	//float pi;

	//double doublePI;


	//alphabet = 'a';
	//year = 2023;
	//month = 4;
	//pi = 3.14f;
	//doublePI = 3.14f;
	//year = month;

	//char ch1 = 'A';
	//char ch2 = 65;

	////printf("%c %d %f %f\n", alphabet, year, pi, doublePI);
	//printf("문자 %c의 아스키 코드 값 : %d\n", ch1, ch1);
	//printf("아스키 코드값이 %d인 문자 : %c\n", ch2, ch2);

	//short sh = 1000;
	//printf(" %d \n", sizeof(sh));

	//float ft = 1.234567890123456789;
	//double db = 1.234567890123456789;

	//printf("%.20f\n", ft);
	//printf("%.20lf\n", db);

	//float f1 = 0.1f;
	//float f2 = f1 + f1 + f1 + f1 + f1 + f1 + f1 + f1 + f1 + f1;

	//printf("%.20f\n",  f2);

	//char name[128] = "hong";
	//printf("%s\n", name);

	//strcpy(name, "gil");
	//printf("%s\n", name);

	/*int iKorean = 70;
	int iEnglish = 80;
	int iMath = 90;

	int iTot = iKorean + iEnglish + iMath;

	printf("국어 : %d, 영어 : %d, 수학 : %d\n", iKorean, iEnglish, iMath);
	printf("총점 : %d\n", iTot);*/

	int age;
	double height;
	printf("나이와 키를 입력하세요 : ");
	scanf("%d%lf", &age, &height);//age의 주소공간에 값을 직접 입력
	printf("나이는 %d, 키는 %0.2f 입니다.\n",age,height);

	char name[128];
	scanf("%s", name);
	printf("이름은 %s 입니다.", name);
	
	return 0;

}