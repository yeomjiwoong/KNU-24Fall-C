#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    BRONZE = 1,  
    SILVER,
    GOLD,
    VIP
} Rank;

typedef struct Customer {
    char* customerName;
    Rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
} Customer;

Customer* head = NULL;

const char* rankToString(Rank rank) {
    switch (rank) {
    case VIP: return "VIP";
    case GOLD: return "GOLD";
    case SILVER: return "SILVER";
    default: return "BRONZE";
    }
}

void addCustomer(char* name, Rank rank, int order_amount, int point) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->customerName = _strdup(name);
    newCustomer->rank = rank;
    newCustomer->order_amount = order_amount;
    newCustomer->point = point;
    newCustomer->prev = NULL;
    newCustomer->next = NULL;

    if (head == NULL) {
        head = newCustomer;
        return;
    }
    
    Customer* current = head;
    while (current != NULL && current->rank >= newCustomer->rank) {
        if (current->rank == newCustomer->rank &&
            current->order_amount < newCustomer->order_amount)
            break;
        current = current->next;
    }

    if (current == head) {
        newCustomer->next = head;
        head->prev = newCustomer;
        head = newCustomer;
    }

    else {
        newCustomer->prev = current->prev;
        newCustomer->next = current;
        current->prev->next = newCustomer;
        if (current != NULL)
            current->prev = newCustomer;
    }
}

void deleteCustomer(char* name) {
    Customer* current = head;
    while (current != NULL) {
        if (strcmp(current->customerName, name) == 0) {
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            free(current->customerName);
            free(current);
            return;
        }
        current = current->next;
    }
}

void printAllCustomers() {
    Customer* current = head;
    printf("\n���� �� ���:\n");
    printf("�̸�\t���\t�ֹ��ݾ�\t����Ʈ\n");
    printf("--------------------------------\n");
    while (current != NULL) {
        printf("%s\t%s\t%d\t%d\n",
            current->customerName,
            rankToString(current->rank),
            current->order_amount,
            current->point);
        current = current->next;
    }
    printf("--------------------------------\n\n");
}

Rank selectRank() {
    int rank;
    printf("�� ��� ����:\n");
    printf("1. BRONZE\n");
    printf("2. SILVER\n");
    printf("3. GOLD\n");
    printf("4. VIP\n");
    printf("����: ");
    scanf_s("%d", &rank);

    if (rank < BRONZE || rank > VIP) {
        printf("�߸��� ��� ����. BRONZE�� �����˴ϴ�.\n");
        return BRONZE;
    }
    return (Rank)rank;
}

int main() {
    int choice;
    char name[100];
    int order_amount, point;
    Rank rank;

    while (1) {
        printf("1. �� �߰�\n");
        printf("2. �� ����\n");
        printf("3. ��ü �� ��ȸ\n");
        printf("4. ���α׷� ����\n");
        printf("����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("�� �̸�: ");
            scanf_s("%s", name, (unsigned)sizeof(name));
            rank = selectRank();  
            printf("�ֹ� �ݾ�: ");
            scanf_s("%d", &order_amount);
            printf("����Ʈ: ");
            scanf_s("%d", &point);
            addCustomer(name, rank, order_amount, point);
            printAllCustomers();
            break;

        case 2:
            printf("������ �� �̸�: ");
            scanf_s("%s", name, (unsigned)sizeof(name));
            deleteCustomer(name);
            printAllCustomers();
            break;

        case 3:
            printAllCustomers();
            break;

        case 4:
            while (head != NULL) {
                Customer* temp = head;
                head = head->next;
                free(temp->customerName);
                free(temp);
            }
            return 0;
        }
    }
}