#include <stdio.h>


typedef struct {
    int id;
    char name[50];
    int price;
} Product;


void printProduct(Product product) {
    printf("��ǰ ID: %d\n", product.id);
    printf("��ǰ��: %s\n", product.name);
    printf("����: %d��\n", product.price);
}

int main() {
    Product products[5]; 
    int count = 0; 
    
    while (count < 5) {
        printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");
        printf("��ǰ ID: ");
        scanf_s("%d", &products[count].id);

        
        if (products[count].id == 0) {
            break;
        }

        printf("��ǰ��: ");
        scanf_s("%s", products[count].name, (unsigned int)sizeof(products[count].name));

        printf("����: ");
        scanf_s("%d", &products[count].price);

        count++; 
    }

   
    printf("\n<<�Էµ� ��ǰ ���>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}