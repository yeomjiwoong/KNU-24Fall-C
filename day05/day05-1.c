#include<stdio.h>
#include<stdlib.h>
#include<string.h>



	
	struct Student {
		int snum;
		int name[100];
		int score;
	};
	int main()
	{
		
	int N;
	struct Student *p;
	
	
	
	printf ("�л� �� : ");
	scanf_s("%d", &N);
	p = (struct Student*)malloc(N * sizeof(struct Student));
	
	
	for (int i = 0; i < N; i++) {
		printf("�й� : ");
		scanf_s("%d", &p[i]);
		printf("�̸� : ");
		char tmp[100];
		scanf_s("%s", p[i].name, 100);
		
		printf("���� : ");
		scanf_s("%d", &p[i].score);
		
	}
	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", p[i].snum, p[i].name, p[i].score);
	}

	free(p);
	
	return 0;
}