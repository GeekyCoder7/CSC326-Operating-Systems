#include <stdio.h>
float average(int a , int b){
float avg =(a+b)/2;
return avg;
}

void getGrades(){

int grade1=0;
printf("Enter your 1st grade: ");
scanf("%d",&grade1);


int grade2=0;
printf("Enter your 2nd grade: ");
scanf("%d",&grade2);

printf("Your 1st grade: %d/100 \n", grade1);

printf("Your 2nd grade: %d/100 \n", grade2);
float avg=average(grade1,grade2);
printf("Your average is %f\n", avg);

} 







int main(){
	unsigned int age;
	printf("Address of var1: %x\n",&age);
	char fname[30];
	char lname[30];
	printf("Please enter your fname: ");
	scanf("%s", fname); 
	printf("Please enter your lname: ");
	scanf("%s", lname); 
	printf("Please enter your age: ");
	scanf("%d", &age); 
	
	printf("Full name: %s %s \n", fname, lname);	
	printf("Age: %d \n", age);
	getGrades();
	return 0;
}
