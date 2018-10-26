#include <stdio.h>


int main(){
	FILE *filePointer;
	char str[255];
	char x;
	filePointer = fopen("file1.txt","r");
	if(filePointer==0){
		printf("Could not open file \n");
	}
	else{
		printf("0: %c\n", fgetc(filePointer));

		fscanf(filePointer,"%s", str);
		printf("1 : %s\n",str);

		fgets(str,255,(FILE*)filePointer);
		printf("2: %s\n",str);

		while((x = fgetc(filePointer))!= EOF){
			printf("%c",x);
		}
	}
	return 0;
}
