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

    
    printf("첫번째 벡터: ");
    scanf_s("%d %d %d", &v1.x, &v1.y, &v1.z);
    printf("두번째 벡터: ");
    scanf_s("%d %d %d", &v2.x, &v2.y, &v2.z);

    
    while (1) {
        printf("\n1. 벡터의 합\n2. 벡터의 차\n3. 벡터의 외적\n4. 벡터의 내적\n5. 종료\n");
        printf("명령 입력: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            result = add(v1, v2);
            printf("벡터의 합은 (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        case 2:
            result = subtract(v1, v2);
            printf("벡터의 차는 (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        case 3:
            result = crossProduct(v1, v2);
            printf("벡터의 외적은 (x: %d, y: %d, z: %d)\n", result.x, result.y, result.z);
            break;
        case 4:
            printf("벡터의 내적은 %d\n", dotProduct(v1, v2));
            break;
        case 5:
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
}