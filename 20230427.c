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

	//int age;
	//double height;
	//printf("나이와 키를 입력하세요 : ");
	//scanf("%d%lf", &age, &height);//age의 주소공간에 값을 직접 입력
	//printf("나이는 %d, 키는 %.2lf 입니다.\n",age,height);

	//char name[128];
	//scanf("%s", name);
	//printf("이름은 %s입니다.", name);
	
	

	
	/*char name[20];

	float degree;
	printf("학점 입력 : ");
	scanf("%f", &degree);
	printf("이름 입력 : ");
	scanf("%s", name);
	printf("%s의 학점은 %.1f입니다.\n", name, degree);

	return 0;*/

	/*double apple;
	int banana;
	int orange;

	apple = 5.0 / 2.0;
	banana = 5 / 2;
	orange = 5 % 2;

	printf("apple : %.1f\n", apple);
	printf("banana : %d\n", banana);
	printf("orange : %d\n", orange);


	int a = 5.0 / 2;
	int b = 5 / 2.0;

	double a2 = 5.0 / 2;
	double b2 = 5 / 2.0;

	printf("%d %d\n", a, b);
	printf("%f %f\n", a, b);
	printf("%d %d\n", a2, b2);
	printf("%f %f\n", a2, b2);*/

	/*int a = 5;

	printf("%d\n", ++a);
	printf("%d\n", a);*/


	/*int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;
	post = (b++) * 3;

	printf("초기값 a = %d, b = %d\n", a, b);
	printf("전위형 : (++a) * 3 = %d\n후위형 : (b++) * 3 = %d\n", pre, post);
	return 0;*/

	/*int a = 5;
	int b = 2;

	printf("%d\n", a > b);
	printf("%d\n", a < b);
	printf("%d\n", a == b);
	printf("%d\n", a != b);*/
	
	/*int a = 5;
	int b = 5;

	printf(" %s\n", b == 4 ? "True" : "False");*/

	/*double a = 4.0, b = 1.2;

	printf(" %.1f + %.1f = %.1f\n", a, b, a + b);
	printf(" %.1f - %.1f = %.1f\n", a, b, a - b);
	printf(" %.1f * %.1f = %.1f\n", a, b, a * b);
	printf(" %.1f / %.1f = %.1f\n", a, b, a / b);*/

	/*int a, b, tot;
	double avg;

	printf("두 과목의 점수 : ");
	scanf("%d%d", &a, &b);

	tot = a + b;

	avg = tot / 2.0;

	printf("평균 : %.1f\n", avg);*/

	/*int iKor = 3;
	int iEng = 5;
	int iMat = 4;
	int iCredit = iKor + iEng + iMat;


	float fKscore = 3.8f;
	float fEscore = 4.4f;
	float fMscore = 3.9f;

	float fGrade = (fKscore + fEscore + fMscore) / 3.0f;;5-

	int iRes = (iCredit >= 10 && fGrade > 4.0f ? 1 : 0);


	printf("%d\n", iRes);
	return 0;*/

	//Q1
	//수명 100년, 한 개비 피우면 3시간 40분 단축, N년간 하루에 M개비피우면 수명은 얼마나 단축?
	//1시간 -> 60분, 1년 -> 365 * 24 * 60분
	int N, M;

	scanf("%d%d", &N, &M);

	const int YEAR = 365 * 24 * 60;
	const int DAY = 24 * 60;
	const int HOUR = 60;

	const int iMaximumLifeMinute = 81 * 365 * 24 * 60;

	//printf("%d\n", iMaximumLifeMinute);
	int iReducedLifeMinute = ((3 * 60 + 40) * M) * (365 * N);
	int iExpectedLifeMinute = iMaximumLifeMinute - iReducedLifeMinute;

	
	
	int iReducedYear = iReducedLifeMinute / YEAR;
	int iReducedDay = (iReducedLifeMinute % YEAR) / DAY;
	int iReducedHour = ((iReducedLifeMinute % YEAR) % DAY) / HOUR;
	int iReducedMinute = iReducedLifeMinute - (iReducedYear * YEAR + iReducedDay * DAY + iReducedHour * HOUR);
	
	int iRemainYear = iExpectedLifeMinute / YEAR;
	int iRemainDay = (iExpectedLifeMinute % YEAR) / DAY;
	int iRemainHour = ((iExpectedLifeMinute % YEAR) % DAY) / HOUR;
	int iRemainMinute = iExpectedLifeMinute - (iRemainYear * YEAR + iRemainDay * DAY + iRemainHour * HOUR);

	printf("줄어든 수명 : %d년 %d일 %d시 %d분\n",iReducedYear, iReducedDay, iReducedHour, iReducedMinute);
	printf("기대 수명 : %d살 %d일 %d시 %d분\n",19 + iRemainYear, iRemainDay, iRemainHour, iRemainMinute);

}