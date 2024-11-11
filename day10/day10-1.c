#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];     
    int score;         
    struct Node* next; 
} Node;

Node* createNode(char* name, int score);
void insertStudent(Node** head, char* name, int score);
void deleteStudent(Node** head, char* name);
void printStudents(Node* head);
void freeList(Node* head);

int main() {
    Node* head = NULL; 
    int choice;
    char name[50];
    int score;

    while (1) {
        printf("------------------------------\n");
        printStudents(head); 
        printf("------------------------------\n");
        printf("1. �л��� ������ �Է�\n");
        printf("2. �л� ���� ����\n");
        printf("3. ���α׷� ����\n");
        printf("input: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: 
            printf("�л� �̸� �Է� : ");
            scanf("%49s", name); 
            printf("%s�� ���� : ", name);
            scanf("%d", &score);
            insertStudent(&head, name, score);
            break;

        case 2: 
            printf("������ �л��� �̸� �Է� : ");
            scanf("%49s", name); 
            deleteStudent(&head, name);
            break;

        case 3: 
            printf("���α׷��� �����մϴ�.\n");
            freeList(head); 
            return 0;

        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
        }
    }
}

Node* createNode(char* name, int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void insertStudent(Node** head, char* name, int score) {
    Node* newNode = createNode(name, score);
    if (*head == NULL || (*head)->score < score) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL && current->next->score >= score) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteStudent(Node** head, char* name) {
    if (*head == NULL) {
        printf("�л� ����� ����ֽ��ϴ�.\n");
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("�л� %s�� ã�� �� �����ϴ�.\n", name);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    }
    else {
        prev->next = current->next;
    }

    printf("�л� %s�� ������ �����Ǿ����ϴ�.\n", name);
    free(current);
}

void printStudents(Node* head) {
    if (head == NULL) {
        printf("�л� ������ �����ϴ�.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%s : %d\n", current->name, current->score);
        current = current->next;
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}
