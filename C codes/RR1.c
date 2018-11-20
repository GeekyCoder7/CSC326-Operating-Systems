 #include <stdio.h>

int main()
{
    FILE *filePointer;
    char str[255];
    int procnbr;
    int pid[20];
    int arrtime[20];
    int burst[20];
    int priority[20];
    int remaining[20];
    int i=0,j=0;
    
    filePointer = fopen("processes1.txt", "r");
    if(filePointer == 0) {
        printf("Could not find file\n");
    }
    else{
        
        printf("How many processes? ");
        scanf("%d", &procnbr);
        fgets(str, 500, (FILE*)filePointer);
        printf("\n%s", str);
        for(i; i<procnbr; i++){
            for (int j =0; j<4 ;j++){
                fscanf(filePointer, "%s", str);
                switch(j) {
                        
                    case 0  :
                         pid[i]=atol(str);
                        break; /* optional */
                    case 1  :
                       arrtime[i]=atol(str);
                        break; /* optional */
                    case 2  :
                        burst[i]=atol(str);
                        remaining[i]=burst[i];
                        break; /* optional */
                    case 3  :
                       priority[i]=atol(str);
                        break; /* optional */
            
                
                }
            }//end for
            printf("%d\t%d\t%d\t%d\n", pid[i], arrtime[i], burst[i], priority[i]);
        }//end for
        printf("\n");
        fclose(filePointer);
        
        int count,time,remain,flag=0,time_quantum;
        int wait_time=0,turnaround_time=0;
        remain=procnbr;
        
        printf("Enter Time Quantum:\t");
        scanf("%d",&time_quantum);
        printf("\n\nProcess\t Waiting Time \tTurnaround Time\n\n");
        for(time=0,count=0;remain!=0;)
        {
            if(remaining[count]<=time_quantum && remaining[count]>0)
            {
                time+=remaining[count];
                remaining[count]=0;
                flag=1;
            }
            else if(remaining[count]>0)
            {
                remaining[count]-=time_quantum;
                time+=time_quantum;
            }
            if(remaining[count]==0 && flag==1)
            {
                remain--;
                printf("P[%d]\t \t%d\t \t%d\t \t%d\n",count,burst[count],time-arrtime[count]-burst[count],time-arrtime[count]);
                wait_time+=time-arrtime[count]-burst[count];
                turnaround_time+=time-arrtime[count];
                flag=0;
            }
            if(count==procnbr-1)
                count=0;
            else if(arrtime[count+1]<=time)
                count++;
            else
                count=0;
        }
        printf("\nAverage Waiting Time= %f\n",wait_time*1.0/procnbr);
        printf("Avg Turnaround Time = %f\n",turnaround_time*1.0/procnbr);
    }
    return 0;
}
