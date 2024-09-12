#include<stdio.h>

int main()
{
	int i;
	
	for (int i = 0; i < 100; i++) {
		if ((i % 3 == 0) && (i % 4 == 0)) {
			if (i % 7 == 0) {
				printf("%d \n ", i);
			}
			else {
				printf("%d\n", i);
			}
		}
		else if (i % 7 == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}