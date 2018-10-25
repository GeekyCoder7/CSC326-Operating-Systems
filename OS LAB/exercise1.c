#include <stdio.h>
int main(){

struct gradeNode{
    char lastName[20];
    double grade;
    struct gradeNode *nextPtr;
}

GradeNodePtr startPtr=null;
GradeNodePtr newPtr;
newPtr = malloc(sizeof(GradeNode));
strcpy(newPtr->lastName,"Jones");
newPtr->grade=91.5;
newPtr->nextPtr=null;

GradeNodePtr startPtr1=null;
GradeNodePtr newPtr;
newPtr = malloc(sizeof(GradeNode));
strcpy(newPtr->lastName,"Adams");
newPtr->grade=91.5;
newPtr->nextPtr=null;

GradeNodePtr startPtr2=null;
GradeNodePtr newPtr;
newPtr = malloc(sizeof(GradeNode));
strcpy(newPtr->lastName,"Thompson");
newPtr->grade=91.5;
newPtr->nextPtr=null;

GradeNodePtr startPtr3=null;
GradeNodePtr newPtr;
newPtr = malloc(sizeof(GradeNode));
strcpy(newPtr->lastName,"Pritchard");
newPtr->grade=91.5;
newPtr->nextPtr=null;


    
    return 0;
}


typedef struct gradeNode GradeNode;
typedef GradeNode *GradeNodePtr;