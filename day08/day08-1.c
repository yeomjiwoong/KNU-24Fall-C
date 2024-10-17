#include <stdio.h>
#include <string.h>

int main() {

    char str[100];   
    char* ptr; 
    int len;

    printf("문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);   
    ptr = str + len - 1; 

    printf("뒤집어진 문자열 :");
    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;             
    }

    printf("\n");

    return 0;
}