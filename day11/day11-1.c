#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    printf("이차방정식의 계수를 입력하세요 (a, b, c): ");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("두 개의 서로 다른 실근: x1 = %.2lf, x2 = %.2lf\n", root1, root2);
    }
    else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("중근: x = %.2lf\n", root1);
    }
    else {
        printf("허근이므로 실근이 없습니다.\n");
    }

    return 0;
}
