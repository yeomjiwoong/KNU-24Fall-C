#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector;


Vector add(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}


Vector subtract(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}


int dotProduct(Vector v1, Vector v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


Vector crossProduct(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

int main() {
    Vector v1, v2, result;
    int choice;

    
    printf("ù��° ����: ");
    scanf_s("%d %d %d", &v1.x, &v1.y, &v1.z);
    printf("�ι�° ����: ");
    scanf_s("%d %d %d", &v2.x, &v2.y, &v2.z);

    
    while (1) {
        printf("\n1. ������ ��\n2. ������ ��\n3. ������ ����\n4. ������ ����\n5. ����\n");
        printf("��� �Է�: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            result = add(v1, v2);
            printf("������ ���� (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        case 2:
            result = subtract(v1, v2);
            printf("������ ���� (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        case 3:
            result = crossProduct(v1, v2);
            printf("������ ������ (x: %d, y: %d, z: %d)\n", result.x, result.y, result.z);
            break;
        case 4:
            printf("������ ������ %d\n", dotProduct(v1, v2));
            break;
        case 5:
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
}