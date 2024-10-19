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

    printf("문자열을 입력하세요 : ");
    scanf_s("%s", str, sizeof(str));


    printf("뒤집어진 문자열 :");
    a(str);

    return 0;
}