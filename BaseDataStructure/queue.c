//
// Created by Jesson on 2020/6/14.
//

#include <stdio.h>
#include <assert.h>
#define MAX_SIZE 10


/***
 *  初始化
 *  队列满了
 *  队列清除
 *  取队首元素
 */
typedef struct Queue{
    int Queue[MAX_SIZE];
    int front; //对头指针
    int rear; //队尾指针
}SeqQueue;

void initQueue(SeqQueue* seqQueue);
int isEmpty(SeqQueue* seqQueue);
int isFull(SeqQueue* seqQueue);
void enterQueue(SeqQueue* seqQueue,int data);
int deleteQueue(SeqQueue* seqQueue,int* data); //队列删除元素，并返回这个元素
void clean(SeqQueue* seqQueue);

void printQueue(SeqQueue* seqQueue);
void testQueue();

void initQueue(SeqQueue* seqQueue){
    seqQueue->front = seqQueue->rear = 0;
}

int isEmpty(SeqQueue* seqQueue){
    if(seqQueue->front == seqQueue->rear){
        return 1;
    }
    return 0;
}

int isFull(SeqQueue* seqQueue){
    if(seqQueue->rear == MAX_SIZE){
        return 1;
    }
    return 0;
}

void enterQueue(SeqQueue* seqQueue,int data){
    //1.判断是否队列是否满了
    if(isFull(seqQueue)){
       printf("queue is Full!!\n");
        return ;
    }
    //保存起来
    seqQueue->Queue[seqQueue->rear] = data;
    seqQueue->rear ++;
}

int deleteQueue(SeqQueue* seqQueue,int* data){
    if(isEmpty(seqQueue)){
        printf("queue is empty!!\n");
        return -1;
    }
    *data =  seqQueue->Queue[seqQueue->front];
    seqQueue->front =(seqQueue->front+1) % MAX_SIZE ;
    return data;
}

void clean(SeqQueue* seqQueue){
    seqQueue->front = seqQueue->rear = 0;
}

void printQueue(SeqQueue* seqQueue){
    assert(seqQueue);
    int i = seqQueue->front;
    while (i < seqQueue->rear){
        printf("%3d",seqQueue->Queue[i]);
        i++;
    }
    printf("\n");
}


void testQueue(){
    SeqQueue queue;
    initQueue(&queue);
    enterQueue(&queue,1);
    enterQueue(&queue,2);
    enterQueue(&queue,3);
    enterQueue(&queue,4);
    enterQueue(&queue,5);
    enterQueue(&queue,6);
    enterQueue(&queue,7);
    printQueue(&queue);
    deleteQueue(&queue,1);
    deleteQueue(&queue,2);
    enterQueue(&queue,8);
    enterQueue(&queue,9);
    enterQueue(&queue,19);
    enterQueue(&queue,119);
    printQueue(&queue);
}

int main(){
    testQueue();
}
