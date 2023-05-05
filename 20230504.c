#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main()
{
	double max, mid, min;

	printf("실수값 3개 입력 : ");
	scanf("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("정렬된 값 출력 : %.1lf,%.1lf,%.1lf\n", max, mid, min);

}

void swap(double* pa, double* pb)
{
	double temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void line_up(double* maxp, double* midp, double* minp)
{
	if (*maxp < *minp)
		swap(minp, maxp);

	if (*maxp < *midp)
		swap(maxp, midp);

	if (*midp < *minp)
		swap(midp, minp);
}