#include<stdio.h>
#include<stdlib.h>
#define stus 3
#define exams 4

void mini(int grades[][exams],int pupils,int tests);
void maxi(int grades[][exams],int pupils,int tests);
void av(int grades[][exams], int pupils, int tests);
void pa(int grades[][exams], int pupils, int tests);
void menu();

int main(){

	void(*processGrades[4])(int[][exams], int, int)
		= { pa, mini, maxi, av };
	int choice = 0;
	int stu;
	int stuG[stus][exams] = 
	{	
		{77,88,99,100},
		{98,87,76,65},
		{70,80,85,88}	
	};
	
	
	
	while(choice != 4){
	
		do {
			menu();

			scanf_s("%d", &choice);
		} while (choice < 0 || choice > 4);

		if (choice != 4)
			(*processGrades[choice])(stuG, stus, exams);
		else
			printf("Program Ended. \n");

	}
	system("pause");
	return 0;
}

void pa( int grades[][exams],int pupils,int tests){
	
	int i,j;
	printf("The array is:\n");
	printf("                [0]  [1]  [2]  [3]");
	
	for(i = 0;i<pupils;i++){
		printf("\nstudentGrades[%d]",i);
		for(j = 0;j<tests;j++){
			printf("%-5d",grades[i][j]);
		}
	}
	
} 

void mini(int grades[][exams],int pupils,int tests){
	
	int i,j,LG = 100;
	
	for(i=0;i<pupils;i++){
		for(j=0;j<tests;j++){
			if(grades[i][j]<LG){
				LG = grades[i][j];
			}
		}
	}
	printf("\n\nLowest grade:%d\n", LG);
	
}

void maxi(int grades[][exams],int pupils,int tests){
	
	int i,j,HG = 0;
	
	for(i=0;i<pupils;i++){
		for(j=0;j<tests;j++){
			if(grades[i][j]>HG){
				HG = grades[i][j];
			}
		}
	}
	
	printf("\n\nHighest grade:%d\n", HG);
	
}

void av(int grades[][exams], int pupils, int tests){
	
	int i,j,t=0;
	
	for (i = 0; i < pupils; i++) {
		t = 0;
		for (j = 0; j < tests; j++) {
			t += grades[i][j];
		}
	}
	printf("The average grade for students %d is %.1f\n",i+1,(double)t/tests);
}

void menu(){
	
	
	
	printf("\n\tEnter a choice:\n"
	"\t0  Print the array of grades\n"
	"\t1  Print the minimum grade\n"
	"\t2  Print the maximum grade\n"
	"\t3  Print the average on all tests for each student\n"
	"\t4  End program\n\tFunction = ");

	
	
}





