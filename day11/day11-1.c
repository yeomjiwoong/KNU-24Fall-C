#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    printf("������������ ����� �Է��ϼ��� (a, b, c): ");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("�� ���� ���� �ٸ� �Ǳ�: x1 = %.2lf, x2 = %.2lf\n", root1, root2);
    }
    else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("�߱�: x = %.2lf\n", root1);
    }
    else {
        printf("����̹Ƿ� �Ǳ��� �����ϴ�.\n");
    }

    return 0;
}
