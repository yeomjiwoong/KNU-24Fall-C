#include <stdio.h>
#include <string.h>

int main() {

    char str[100];   
    char* ptr; 
    int len;

    printf("���ڿ��� �Է��ϼ���: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);   
    ptr = str + len - 1; 

    printf("�������� ���ڿ� :");
    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;             
    }

    printf("\n");

    return 0;
}