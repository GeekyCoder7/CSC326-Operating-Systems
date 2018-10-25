#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Sum(int a,int b){
    return a+b;
}

struct student{//class prototype
    int id;
    char name[20];
    float percentage;
};

int main(){
    int i;    // i is an int
    int *p;   // this is a * in a type-name. 
    p = &i;   // use & operator to get a pointer to i, assign that to p.
    //you only put the * once. Once declaring, you don't put * anymore
    int age;
    //int *age = &age;
   
    struct student record1;
    record1.id=20100000;
    strcpy(record1.name,"John");
    record1.percentage=72.1;

    printf("id = %d, Name = %s , Percentage = %f \n", record1.id,record1.name,record1.percentage);
   
    puts("Enter your age:");
    scanf("%d",&age);
  
    int sumf=Sum(age,age);
    printf("Your function values is %d\n",sumf);
    printf("Hello World!\nMy age is %d\n",age);
    printf("%d\n",52);
    printf("%f\n",52.3);

    //scanf("%s",)

    return 0;
}




/*
% in C: PlaceHolder (format specifier to print)
%d for integer
%ld for large integer
%f for float
%lf for large float
%c for char
%s for string
%x for hexadecimal(When printing memory address)


* in C: Pointer. A pointer is a variable whose value is the address of another variable
Example:

int i;    // i is an int
int *p;
p=&i;
printf("%d",*p) => *p=value of i, p = address of i



& in C: address

int x;
void *p = &x; p will now point to x,
as we are assigning the address of x to the pointer p.
*/