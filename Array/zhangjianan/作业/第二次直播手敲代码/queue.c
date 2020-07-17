#include <stdio.h>
#include <malloc.h>
#include <semaphore.h>
#include <Signal.h>
#include <stdlib.h> // exit(), EXIT_SUCCESS
#include <pthread.h> // pthread_create(), pthread_join()
#include <assert.h>
#define MAX_SIZE 10
typedef struct Queue{
    int Queue[MAX_SIZE];
    int front;//队头指针
    int rear;//队尾指针
}SeqQueue;

void initQueue(SeqQueue* seqQueue);
int isEmpty(SeqQueue* seqQueue);
int isFull(SeqQueue* seqQueue);
void enterQueue(SeqQueue* seqQueue,int  data);
int deleteQueue(SeqQueue* seqQueue);
void clean(SeqQueue* seqQueue);
void printQueue(SeqQueue* seqQueue);
void initQueue(SeqQueue* seqQueue){
    seqQueue->front=0;
    seqQueue->rear=0;
}
int isEmpty(SeqQueue* seqQueue){
    if (seqQueue->front==seqQueue->rear) {
        return 1;
    }
    return 0;
}
int isFull(SeqQueue* seqQueue){
    if (seqQueue->rear==MAX_SIZE) {
        return 1;
    }
    return 0;
}
void enterQueue(SeqQueue* seqQueue,int  data){
    if (isFull(seqQueue)){
        printf("isFull \n");
        return ;
    }
    seqQueue->Queue[seqQueue->rear]=data;
    seqQueue->rear++;
}
int deleteQueue(SeqQueue* seqQueue){
    if (isEmpty(seqQueue)){
        printf("isEmpty \n");
        return -1;
    }
    int data=seqQueue->Queue[seqQueue->front];
    seqQueue->front=seqQueue->front+1;

    return data;
}
void clean(SeqQueue* seqQueue){
    seqQueue->front=seqQueue->rear=0;
}
void printQueue(SeqQueue* seqQueue){
    int i = seqQueue->front;
    for (; i <seqQueue->rear; ++i) {
        printf("%3d  ", seqQueue->Queue[i]);
    }
    printf(" \n");
}
int main() {
//    SeqQueue* seqQueue=malloc(sizeof( SeqQueue*));
    SeqQueue seqQueue;
    initQueue(&seqQueue);
    enterQueue(&seqQueue, 1);
    enterQueue(&seqQueue, 2);
    enterQueue(&seqQueue, 3);
    enterQueue(&seqQueue, 4);
    enterQueue(&seqQueue, 5);
    printQueue(&seqQueue);
    deleteQueue(&seqQueue);
    enterQueue(&seqQueue, 6);
    enterQueue(&seqQueue, 7);
    enterQueue(&seqQueue, 8);
    enterQueue(&seqQueue, 9);
    enterQueue(&seqQueue, 10);
    enterQueue(&seqQueue, 11);
    enterQueue(&seqQueue, 11);

    printQueue(&seqQueue);
    return 0;
}

