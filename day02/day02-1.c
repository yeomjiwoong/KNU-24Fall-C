#include<stdio.h>
int main()
{
	int opr;
	printf("연산타입 : ");
	scanf_s("%d", &opr);

	double num1, num2;
	printf("첫번째 숫자:");
	scanf_s("%lf", &num1);
	printf("두번째 숫자: ");
	scanf_s("%lf", &num2);
	

	double result = 0;
	if (opr == 1) {
		result = num1 + num2;
	}
	else if (opr == 2) {
		result = num1 - num2;
	}
	printf("result = %lf", result);

	return 0;
}