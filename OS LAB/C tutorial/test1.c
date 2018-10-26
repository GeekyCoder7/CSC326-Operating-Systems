#include <stdio.h>

int main(){
	int count;
	printf("Please enter a number: ");
	scanf("%d", &count); 
	printf("The number is %d \n", count);
	
	return 0;
}

/*
&: address of the variable
%: in order to replace the variable's address , %d: integer, %f: float, %c: char, %s: string.
if we have a string => %s we dont put & for the address
We cant do "The number is " + count like java
*/