#include <stdio.h>



void a(char* str) {

    char* end = str;
    while (*end != '\0') {
        end++;
    }

    end--;


    while (end >= str) {
        putchar(*end);
        end--;
    }
    putchar('\n');
}

int main() {
    char str[100];

    printf("���ڿ��� �Է��ϼ��� : ");
    scanf_s("%s", str, sizeof(str));


    printf("�������� ���ڿ� :");
    a(str);

    return 0;
}