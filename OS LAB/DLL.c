#import<stdio.h>
#import<stdlib.h>

struct listNode{
char data;
struct listNode * next;
struct listNode * prev;
};

typedef struct listNode node; //alias to struct listNode
typedef node * nodeptr; //alias to node *


void insert(nodeptr *sptr, char value);
char delete(nodeptr *sptr, char value);
int isEmpty(nodeptr sptr);
void printList(nodeptr currentptr);

void instructions();

int main()
{

unsigned int choice;
char item; //element to insert or delete, input by user

nodeptr start = NULL; //initially there are no nodes in the list

instructions();

puts("?");
scanf("%u", &choice);


while(choice != 4){
	switch(choice) {
	case 1: 
		printf("%s", "Enter a character to insert: ");
		scanf("\n%c", &item);
		insert(&start, item);
		printList(start);
	break;

	case 2:
		printf("%s", "Enter a character to delete: ");
		scanf("\n%c", &item);

		if(!isEmpty(start))  //list has at least one node
		{
			delete(&start, item);
			printList(start);
		}
		else {
			puts("List is empty. \n");
		}
	break;

	
	case 3: 
		printList(start);
	break;
	

	default:
		puts("Invalid choice.");
		instructions();
	break;
	}//endswitch


printf("%s", "? ");
scanf("%u", &choice);
}//endwhile


puts("End of program");
puts("Jimmy is Noob");
return 0;
}//endmain


void instructions()
{
puts("Enter a choice 1-4: \n"
" 1- to insert an element into the list. \n"
" 2- to delete an element from the list. \n"
" 3- to print the List.\n"
" 4- to end.");

}


void insert(nodeptr *sptr, char value)
{

nodeptr newptr; //pointer to a new node
nodeptr previous; //pointer to a previous node in the list
nodeptr current;


newptr = malloc(sizeof(node)); //create a new node

if(newptr != NULL) {  //if the node was successfully created
	newptr->data = value;
	newptr->next = NULL;
   

	previous = NULL;
	current = *sptr;

	while(current != NULL && value > current->data) 
	{
		previous = current; 
		current = current->next;
	}//endwhile

	//insert a new node at the beginning of the list
	if(previous == NULL) 
	{
		newptr->next = *sptr;
		*sptr = newptr;
	}//endif
	else { //insert a new node between previous and current
		previous->next = newptr;
		newptr->next = current;
	}//endelse
	}//endif
else {	
	printf("%c Not inserted. No memory available \n", value);
}//endelse

}//end insert()	



void printList(nodeptr current){
//if list is empty

if(isEmpty(current)) {
	puts("list is empty \n");
}//end if

else {
	puts("The list is: ");

	while(current != NULL) {
		printf("%c --> ", current->data);
		current = current->next;
	}//endwhile

	puts("NULL");
}//endelse

}//end printList



int isEmpty(nodeptr sptr) 
{
	return sptr == NULL; //logical expression. If NULL, returns true (1) and list is empty, returns false (0) otherwise. 
}// end isEmpty 





char delete(nodeptr *sptr, char value)
{
	nodeptr previous;
	nodeptr current;
	nodeptr temp;


	//delete first node
	if(value == (*sptr)->data) 
	{
		temp = *sptr;
		*sptr = (*sptr)->next;
		free(temp);
		return value;
	}//endif
	else {
		previous = *sptr;
		current = (*sptr)->next;

		//loop to find the correct location in the list (search)
		while(current != NULL && current->data != value)
		{
			previous = current;
			current = current->next;
		}//endwhile

		//delete the node at current pointer
		if(current != NULL) //if node exists
		{
			temp = current;
			previous->next = current->next;
			free(temp); 
			return value;
		}//endif
	}//endelse


	return '\0';

}//end delete()



