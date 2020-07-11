//
// Created by 谢涛 on 2020/7/3.
//

#include <stdio.h>
#include <assert.h>
#define MAX_SIZE 6
#define true 1;
#define false 0;
typedef int DATA_TYPE ;
typedef struct RingBuffer{
    int Queue[MAX_SIZE];
    int front;//头指针
    int rear;//尾指针
}SeqQueue;
void initQueue(SeqQueue* seqQueue);//初始化
int isEmpty(SeqQueue* seqQueue);//判断是否为空
int isFull(SeqQueue* seqQueue);//判断是否已满
void putQueue(SeqQueue* seqQueue,int data);//添加元素
DATA_TYPE getQueueNext(SeqQueue* seqQueue); //获取队列下一个元素
void clean(SeqQueue* seqQueue);//清空队列


void initQueue(SeqQueue* seqQueue){
    seqQueue->front = seqQueue->rear = 0;
}
int isEmpty(SeqQueue* seqQueue){
    if (seqQueue->front == seqQueue->rear){
        return true;
    }
    return false;
}
int isFull(SeqQueue* seqQueue){
    if ((seqQueue->rear+1)% MAX_SIZE == seqQueue->front ){
       return true;
    }
    return false;
}
void putQueue(SeqQueue* seqQueue,int data){
    if (isFull(seqQueue)){
        seqQueue->front = (seqQueue->front+1) % MAX_SIZE;
    }

    seqQueue->Queue[seqQueue->rear] = data;
    seqQueue->rear = (seqQueue->rear +1)% MAX_SIZE;
}
DATA_TYPE getQueueNext(SeqQueue* seqQueue){
    if(isEmpty(seqQueue)){
        return NULL;
    }
    DATA_TYPE node = seqQueue->Queue[seqQueue->front];
    seqQueue->front = (seqQueue->front+1) % MAX_SIZE;
    return node;
}
void clean(SeqQueue* seqQueue){
    seqQueue->front = seqQueue->rear = 0;
}

void printQueue(SeqQueue*  seqQueue){
    while (!isEmpty(seqQueue)){
        printf("%d",getQueueNext(seqQueue));
    }
}

int main(){
    SeqQueue  queue;
    initQueue(&queue);
    putQueue(&queue,11);
    putQueue(&queue,22);
    putQueue(&queue,33);
    putQueue(&queue,44);
//    putQueue(&queue,55);
//    putQueue(&queue,66);
//    putQueue(&queue,77);
    printQueue(&queue);

}