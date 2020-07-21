//
// Created by 张佳男 on 2020/7/15.
//
#include <stdio.h>
#define MAX_SIZE 10
typedef struct Queue{
    int Queue[MAX_SIZE];
    int front;//队头指针
    int rear;//队尾指针
}SeqCirQueue;

void initQueue(SeqCirQueue* seqQueue);
int isEmpty(SeqCirQueue* seqQueue);
int isFull(SeqCirQueue* seqQueue);
void enterQueue(SeqCirQueue* seqQueue,int  data);
int deleteQueue(SeqCirQueue* seqQueue);
void clean(SeqCirQueue* seqQueue);
void printQueue(SeqCirQueue* seqQueue);
void initQueue(SeqCirQueue* seqQueue){
    seqQueue->front=0;
    seqQueue->rear=0;
}
int isEmpty(SeqCirQueue* seqQueue){
    if ((seqQueue->front%MAX_SIZE)+1==(seqQueue->rear%MAX_SIZE)) {
        return 1;
    }
    return 0;
}
int isFull(SeqCirQueue* seqQueue){
    if (seqQueue->rear!=0&&((seqQueue->rear+1)%MAX_SIZE)-1==seqQueue->front) {
        return 1;
    }
    return 0;
}
void enterQueue(SeqCirQueue* seqQueue,int  data){
    if (isFull(seqQueue)){
        printf("isFull \n");
        return ;
    }
    seqQueue->Queue[seqQueue->rear]=data;
    seqQueue->rear=(seqQueue->rear+1)%MAX_SIZE;
}
int deleteQueue(SeqCirQueue* seqQueue){
    if (isEmpty(seqQueue)){
        printf("isEmpty \n");
        return -1;
    }
    int data=seqQueue->Queue[seqQueue->front];
    seqQueue->front=(seqQueue->front+1)%MAX_SIZE;

    return data;
}
void clean(SeqCirQueue* seqQueue){
    seqQueue->front=seqQueue->rear=0;
}
void printQueue(SeqCirQueue* seqQueue){
    if (seqQueue->front<seqQueue->rear) {
        int i = seqQueue->front;
        for (; i <seqQueue->rear; ++i) {
            printf("%3d  ", seqQueue->Queue[i]);
        }
        printf(" \n");
    } else {
        int i = seqQueue->front;
        int j = 0;
        for (; i <MAX_SIZE; ++i) {
            printf("%3d  ", seqQueue->Queue[i]);
        }
        for (; j <seqQueue->rear; ++j) {
            printf("%3d  ", seqQueue->Queue[j]);
        }
        printf(" \n");
    }

}
int main() {
//    SeqQueue* seqQueue=malloc(sizeof( SeqQueue*));
    SeqCirQueue seqQueue;
    initQueue(&seqQueue);
    enterQueue(&seqQueue, 1);
    enterQueue(&seqQueue, 2);
    enterQueue(&seqQueue, 3);
    enterQueue(&seqQueue, 4);
    enterQueue(&seqQueue, 5);
    printQueue(&seqQueue);
    deleteQueue(&seqQueue);
    deleteQueue(&seqQueue);
    deleteQueue(&seqQueue);
    deleteQueue(&seqQueue);
    deleteQueue(&seqQueue);
    enterQueue(&seqQueue, 6);
    enterQueue(&seqQueue, 7);
    enterQueue(&seqQueue, 8);
    enterQueue(&seqQueue, 9);
    enterQueue(&seqQueue, 10);
    enterQueue(&seqQueue, 11);
    enterQueue(&seqQueue, 12);
    enterQueue(&seqQueue, 13);
    enterQueue(&seqQueue, 14);
    deleteQueue(&seqQueue);
    deleteQueue(&seqQueue);
    enterQueue(&seqQueue, 15);
    enterQueue(&seqQueue, 16);
    printQueue(&seqQueue);
    return 0;
}