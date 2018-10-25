#import<stdio.h>
#import<stdlib.h>

struct listNode{
    char data;
    struct listNode * next;
    struct listNode * prev;
};

typedef struct listNode node;
typedef node * ptrNode;


void insert(ptrNode *sptr, char value);//INSERT
char delete(ptrNode *sptr, char value); //DELETE BY VALUE
int isEmpty(ptrNode sptr);//CHECKS IF EMPTY OR NOT
void printList(ptrNode ptrCurrent);//PRINTS THE LIST

int count=0;

void printMenu();

int main(){

int num;
char item;

count = 0;

ptrNode start = NULL;

printMenu();

puts("?");
scanf("%u", &num);


while(num != 4){
	switch(num) {
	case 1:
		printf("%s", "Enter a character to insert: ");
		scanf("\n%c", &item);
		insert(&start, item);
		printList(start);
	break;

	case 2:
		printf("%s", "Enter a character to delete: ");
		scanf("\n%c", &item);

		if(!isEmpty(start)){
			delete(&start, item);
			printList(start);
		}else {
			puts("Empty list. \n");
		}
	break;


	case 3:
		printList(start);
	break;


	default:
		puts("Invalid number.");
		printMenu();
	break;
	}


printf("%s", "\n? ");
scanf("%u", &num);
}


puts("End of program");

return 0;
}

void printMenu(){
puts("Enter a num 1-4: \n"
" 1- to insert an element into the list. \n"
" 2- to delete an element from the list. \n"
" 3- to print the List.\n"
" 4- to end.");
}


void insert(ptrNode *sptr, char value){

ptrNode ptrNew;
ptrNode current = *sptr;
ptrNew = malloc(sizeof(node));

if(ptrNew != NULL) {
	ptrNew->data = value;
	ptrNew->next = NULL;
	ptrNew->prev= NULL;

	
	if(*sptr == NULL){
		*sptr = ptrNew;
		count++;
	}else{
	    int i = 0;
		while(i< count-1){
		    current = current->next;
		    i++;
		}

		current->next = ptrNew;
		ptrNew->prev=current;
		ptrNew->next= *sptr;
		(*sptr)->prev=ptrNew;
		count++;
	}

    }else {
        printf("%c Not inserted. No memory available \n", value);
    }
}



void printList(ptrNode current){

    if(isEmpty(current)) {
        puts("list is empty \n");
    }else{
        puts("The list is: ");
        int i=0;
        while (i< count) {
            printf("%c --> ", current->data);
            current = current->next;
            i++;
        }
        if(current!=NULL)
        {
        printf("%c", current->data);
        }

    }

}



int isEmpty(ptrNode sptr){
	return sptr == NULL;
}





char delete(ptrNode *sptr, char value)
{
	ptrNode previous;
	ptrNode current;
	ptrNode temp;
	ptrNode lastnode;

	//delete first node
	if(value == (*sptr)->data)
	{
		temp = *sptr;
		lastnode= (*sptr)->prev;
		*sptr = (*sptr)->next;
		if ((lastnode != NULL) && (lastnode != *sptr))//if list contains more than one element
        {
            lastnode->next = *sptr;
            (*sptr)-> prev = lastnode;
        }
		free(temp);
		count--;
		return value;
	}//endif
	else {
		previous = *sptr;
		current = (*sptr)->next;

		//loop to find the correct location in the list (search)
		int i =0;
		while(i<count && current->data != value)
		{
			previous = current;
			current = current->next;
			i++;
		}//endwhile

		//delete the node at current pointer
		if(i<count) //if node exists
		{
			temp = current;
			if(previous != current->next)//if more than 2 nodes
			{
			    previous->next = current->next;
                current->next->prev=previous;
			}
			else
            {
                previous->next = NULL;
                previous->prev =NULL;
            }
			free(temp);
			count--;
			return value;
		}//endif
	}//endelse


	return '\0';

}//end delete()
