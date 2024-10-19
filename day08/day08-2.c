#include <stdio.h>
#include <stdlib.h>


#define SIZE 10

void fillrandom(int array[SIZE][SIZE]);
void printarray(int array[SIZE][SIZE]);
void movepointer(void* array);


void fillrandom(int array[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = rand() % 20 + 1; 
        }
    }
}


void printarray(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
}


void movepointer(void* array) {
    int(*arr)[SIZE] = array; 
    int x = 0, y = 0;         
    int* ptr = &arr[x][y];    

    while (1) {
        int move = *(ptr);  
        printf("현재 위치: (%d, %d), 배열 값: %d\n", x, y, move);

        
        int new_x = x + move / SIZE;  
        int new_y = y + move % SIZE;  

        while (new_y >= SIZE) {
            new_y -= SIZE;
            new_x++;
       }
        if (new_x >= SIZE) {
            printf("더 이상 이동할 수 없습니다.\n");
            printf("최종 위치: (%d, %d), 최종 배열 값: %d\n", x, y, arr[x][y]);
            break;
        }

      
        x = new_x;
        y = new_y;

       
        ptr = &arr[x][y];
    }
}

int main() {
    int array[SIZE][SIZE];

    fillrandom(array);  
    printarray(array);  
    movepointer(array); 
    
    return 0;
}
