#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define TRUE 1

buffer_item buffer[BUFFER_SIZE];

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

int ptrInsert = 0;
int ptrRemove = 0;

void *producer(void *param);
void *consumer(void *param);

int insert_item(buffer_item item){
    int returnValue = 0;
    
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    
    if (ptrInsert < BUFFER_SIZE) {
        buffer[ptrInsert++] = item;
        ptrInsert = ptrInsert % 5;
        }
    else {
        returnValue = -1;
    }
    
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    
    return returnValue;
}

int remove_item(buffer_item *item){
    int returnValue;
    
    sem_wait(&full);
    
    pthread_mutex_lock(&mutex);
    if (ptrInsert > 0) {
        *item = buffer[ptrRemove];
        buffer[ptrRemove++] = -1;
        ptrRemove = ptrRemove % 5;
    }
    else{
        returnValue = -1;
    }
    
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    
    return returnValue;
}


void *producer(void *param){
    buffer_item random;
    int r;
    
    while(TRUE){
        r = rand() % 5;
        sleep(r);
        random = rand();
        
        if(insert_item(random)){
            fprintf(stderr, "Error!");
        }
        printf("Producer produced %d \n", random);
        
    }
    
}

void *consumer(void *param){
    buffer_item random;
    int r;
    
    while(TRUE){
        r = rand() % 5;
        sleep(r);
        
        if(remove_item(&random)){
            fprintf(stderr, "Error!");
        }
        else{
            printf("Consumer consumed %d \n", random);
        }
    }
}


int main(int argc, char *argv[]){
    int sleepTime, producerThreads, consumerThreads;
    int i, j;
    
    if(argc != 4){
        fprintf(stderr, "Usage: <sleep time> <producer threads> <consumer threads>\n");
        return -1;
    }
    
    sleepTime = atoi(argv[1]);
    producerThreads = atoi(argv[2]);
    consumerThreads = atoi(argv[3]);
    
    printf("%d\n",pthread_mutex_init(&mutex, NULL));
    printf("%d\n",sem_init(&empty, 0, 5));
    printf("%d\n",sem_init(&full, 0, 0));
    srand(time(0));
    
   
    
    for(i = 0; i < producerThreads; i++){
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, producer, NULL);
    }
    
    for(j = 0; j < consumerThreads; j++){
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, consumer, NULL);
    }
    
    
    sleep(sleepTime);
    return 0;
}


