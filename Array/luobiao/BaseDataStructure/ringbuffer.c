//
// Created by Jesson on 2020/6/14.
//

#include <stdio.h>
#include <assert.h>
#define MAX_SIZE 10
typedef int DATA_TYPE ;

typedef struct Queue{
    DATA_TYPE Queue[MAX_SIZE];
    int front; //对头指针
    int rear; //队尾指针
}SeqCirQueue;


void initQueue(SeqCirQueue* seqQueue);
int isEmpty(SeqCirQueue* seqQueue);
int isFull(SeqCirQueue* seqQueue);
void enterQueue(SeqCirQueue* seqQueue,int data);
int deleteQueue(SeqCirQueue* seqQueue,int* data); //队列删除元素，并返回这个元素
void clean(SeqCirQueue* seqQueue);
void printQueue(SeqCirQueue*  seqQueue);



void printQueue(SeqCirQueue* seqQueue);
void testQueue();

void initQueue(SeqCirQueue* seqQueue){
    seqQueue->front = seqQueue->rear = 0;
}

int isEmpty(SeqCirQueue* seqQueue){
    if(seqQueue->front == seqQueue->rear){
        return 1;
    }
    return 0;
}

int isFull(SeqCirQueue* seqQueue){
    if((seqQueue->rear+1) % MAX_SIZE  == seqQueue->front){
        return 1;
    }
    return 0;
}


void enterQueue(SeqCirQueue* seqQueue,DATA_TYPE data){
    //1.判断是否队列是否满了
    if(isFull(seqQueue)){
        printf("queue is Full!!\n");
        return ;
    }
    //保存起来
    seqQueue->Queue[seqQueue->rear] = data;
    seqQueue->rear = (seqQueue->rear +1)% MAX_SIZE;
}

int deleteQueue(SeqCirQueue* seqQueue,DATA_TYPE* data){
    if(isEmpty(seqQueue)){
        printf("queue is empty!!\n");
        return -1;
    }
    *data =  seqQueue->Queue[seqQueue->front];
    seqQueue->front =(seqQueue->front)+1;
    return *data;
}

/*循环队列*/
void printQueue(SeqCirQueue*  seqQueue){
    assert(seqQueue);
    int i = seqQueue->rear;
    if(seqQueue->front < seqQueue->rear){
        for (;i<seqQueue->rear;i++){
            printf("%3d",seqQueue->Queue[i]);
        }
    }else {
        //出队很快
        for (;i<seqQueue->rear + MAX_SIZE;i++){
            printf("%3d",seqQueue->Queue[i]);
        }
    }
    printf("\n");
}


void testQueue(){
    SeqCirQueue  queue;
    DATA_TYPE  data;
    initQueue(&queue);
    enterQueue(&queue,1);
    enterQueue(&queue,2);
    enterQueue(&queue,3);
    enterQueue(&queue,4);
    enterQueue(&queue,5);
    enterQueue(&queue,6);
    enterQueue(&queue,7);
    printQueue(&queue);
    deleteQueue(&queue,&data);
    deleteQueue(&queue,&data);
    enterQueue(&queue,8);
    enterQueue(&queue,9);
    enterQueue(&queue,19);
    enterQueue(&queue,119);
   enterQueue(&queue,120);
    printQueue(&queue);
}

int main(){
    testQueue();

}
