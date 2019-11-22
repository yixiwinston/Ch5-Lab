#include<stdio.h>
#include<stdlib.h>
#define stus 3
#define exams 4

int mini(const int grades[][exams],int pupils,int tests);
int maxi(const int grades[][exams],int pupils,int tests);
double av(const int SetOfGrades[],int tests);
void pa(const int grades[][exams],int pupils,int tests);
void menu();

int main(){

	int overflag = 0;
	int stu,FI;
	const int stuG[stus][exams] = 
	{	
		{77,88,99,100},
		{98,87,76,65},
		{70,80,85,88}	
	};
	
	
	
	while(1){
	
	menu();

	scanf_s("%d",&FI);
	
	switch(FI){
		
		case 0:
			printf("The array is:\n");
			pa(stuG,stus,exams);
			break;
			
		case 1:
			printf("Lowest grade:%d\n",mini(stuG,stus,exams));
			break;
			
		case 2:
			printf("Highest grade:%d\n",maxi(stuG,stus,exams));
			break;
			
		case 3:
			for(stu = 0;stu<stus;stu++){
		
			printf("The average grade for students %d is %.1f\n",
			stu ,av(stuG[stu],exams));
		
			}
			break;
			
		case 4:
			printf("Program Ended\n");
			break;
			
		default:
			printf("Error!!!\n\n\n");
			break;	
	}
	
	if(FI == 4)
		break;


	
	
	}
	system("pause");
	return 0;
}

void pa(const int grades[][exams],int pupils,int tests){
	
	int i,j;
	
	printf("                [0]  [1]  [2]  [3]");
	
	for(i = 0;i<pupils;i++){
		printf("\nstudentGrades[%d]",i);
		for(j = 0;j<tests;j++){
			printf("%-5d",grades[i][j]);
		}
	}
	
} 

int mini(const int grades[][exams],int pupils,int tests){
	
	int i,j,LG = 100;
	
	for(i=0;i<pupils;i++){
		for(j=0;j<tests;j++){
			if(grades[i][j]<LG){
				LG = grades[i][j];
			}
		}
	}
	
	return LG;
	
}

int maxi(const int grades[][exams],int pupils,int tests){
	
	int i,j,HG = 0;
	
	for(i=0;i<pupils;i++){
		for(j=0;j<tests;j++){
			if(grades[i][j]>HG){
				HG = grades[i][j];
			}
		}
	}
	
	return HG;
	
}

double av(const int SetOfGrades[],int tests){
	
	int i,t=0;
	
	for(i=0;i<tests;i++){
		t += SetOfGrades[i];
	}
	
	return(double)t / tests;
	
}

void menu(){
	
	
	
	printf("\n\tEnter a choice:\n"
	"\t0  Print the array of grades\n"
	"\t1  Print the minimum grade\n"
	"\t2  Print the maximum grade\n"
	"\t3  Print the average on all tests for each student\n"
	"\t4  End program\n\tFunction = ");

	
	
}





