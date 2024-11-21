#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x) + sin(x);
}

double integrate(double a, double b, int n) {
    double width = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double x = a + i * width;
        sum += f(x) * width;
    }

    return sum;
}

int main() {
    double a, b;
    int max_exponent;

    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%lf", &a);
    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%lf", &b);
    printf("실행할 최대 구간을 입력하세요 (2^n): ");
    scanf_s("%d", &max_exponent);

    printf("\n");

    int n = 1;

    for (int i = 0; i <= max_exponent; i++) {
        double result = integrate(a, b, n);
        printf("구간: %d 적분결과: %.6f\n", n, result);
        n *= 2;
    }

    return 0;
}

