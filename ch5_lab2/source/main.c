#include<stdio.h>
#include<stdlib.h>
#define ISSUES 5
#define RATINGS 10

void RecordResponse(int i,int res);
void HR();
void LR();
float AVR(int issue);
void DisplayResults();

int responses[ISSUES][RATINGS];
const char *topics[ISSUES] = { "GlobalWarming","TheEconomy",
							 "War","HealthCare","Edution" };

int main(){

	int res,i;

	do{
		
		printf("Please rate the following topic on a scale  from 1 ~ 10"
				"\n1 = least important,10 = most important\n"	);
		
		for(i=0;i<ISSUES;i++){
			
			do{
				
				printf("%s",topics[i]);
				printf("?\t");
				scanf_s("%d",&res);
				
			}while(res<1 || res > 10);
			
			RecordResponse(i,res);			

		}
		
		printf("Enter 1 to stop,or Enter 0 to rate the issues again.");
		scanf_s("%d",&res);
		
	}while(res != 1);

	DisplayResults();

	system("pause");
	return 0;
}

void RecordResponse(int i,int rating){

	responses[i][rating - 1]++;

} 
void HR(){

	int hR = 0;
	int hT = 0;
	int i,j;

	for(i=0;i<ISSUES;i++){
		
		int tR = 0;
		
		for(j=0;j<RATINGS;j++)
			tR += responses[i][j] * (j + 1);
			
		if(hR < tR){
			
			hR = tR;
			hT = i;
			
		}
		
	}
	
	printf("The highest rated topic was");
	printf("%s",topics[hT]);
	printf("with a total rating of %d\n",hR);
} 
void LR(){

	int lR = 0;
	int lT = 0;
	int i,j;

	for(i=0;i<ISSUES;i++){
		
		int tR = 0;
		
		for(j=0;j<RATINGS;j++)
			tR += responses[i][j] * (j + 1);
			
		if(i == 0)	
			lR = tR;
			
		if(lR > tR){
			
			lR = tR;
			lT = i;
			
		}
		
	}
	
	printf("The lowest rated topic was");
	printf("%s",topics[lT]);
	printf("with a total rating of %d\n",lR);


} 
float AVR(int issue){

	float t = 0;
	int count = 0;
	int j;

	for (j = 0; j < RATINGS; j++) {

		t += responses[issue][j] * (j + 1);
		count += responses[issue][j];

	}

	return t / count;

} 
void DisplayResults	(){

	int i, j;
	printf("%20s","Topic");

	for (i = 1; i <= RATINGS; i++)
		printf("%4d", i);

	printf("%20s\n", "Average Rating");
	
	for (i = 0; i < ISSUES; i++) {

		printf("%20s", topics[i]);
		for(j=0;j<RATINGS;j++)
			printf("%4d", responses[i][j]);
		printf("%20.2f\n", AVR(i));
	}
	HR();
	LR();

} 


