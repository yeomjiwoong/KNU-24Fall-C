#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BAR 20

int main(void) {
    double x, y;
    long long int count = 0, circle = 0;
    long long int total_points = 1000000000; 
    long long int print_step = 10000000;      
    double pi_estimate;
    int progress = 0;

    srand(time(NULL)); 

    for (count = 1; count <= total_points; count++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if (x * x + y * y <= 1) {
            circle++;
        }

        if (count % print_step == 0) {
         
            pi_estimate = 4.0 * circle / count;

           
            progress = (int)((count * 100) / total_points);

        
            int bar_progress = (progress * BAR) / 100;  

            printf("%d%% 진행 · 원주율: %.6f ", progress, pi_estimate);
          
            for (int i = 0; i < bar_progress; i++) {
                printf("*"); 
            }
            for (int i = bar_progress; i < BAR; i++) {
                printf(" ");  
            }
            printf("\n");
        }
    }

  
    pi_estimate = 4.0 * circle / total_points;
    printf("원주율 : %.6f\n", pi_estimate);

    return 0;
}