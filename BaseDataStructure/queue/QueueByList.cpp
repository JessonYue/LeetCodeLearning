//
// Created by Jesson on 2021/2/8.
//

#include <clocale>
#include <cstdio>
#include <malloc.h>

/*通过链表实现队数据结构，在设计思想上还是双指针的办法,请大家完善 比如printQueue 获取元素等*/
typedef struct QueueNode{
    int data;
    struct QueueNode* next;
};

QueueNode * initQueue(){
    QueueNode * queue=(QueueNode*)malloc(sizeof(QueueNode));
    queue->next=NULL;
    return queue;
}
QueueNode* enQueue(QueueNode * rear,int data){
    QueueNode * enElem=(QueueNode*)malloc(sizeof(QueueNode));
    enElem->data=data;
    enElem->next=NULL;
    //使用尾插法向链队列中添加数据元素
    rear->next=enElem;
    rear=enElem;
    return rear;
}
QueueNode* DeQueue(QueueNode * top,QueueNode * rear){
    QueueNode * p = NULL;
    if (top->next==NULL) {
        printf("\n队列为空");
        return rear;
    }
    p=top->next;
    printf("%d ",p->data);
    top->next=p->next;
    if (rear==p) {
        rear=top;
    }
    free(p);
    return rear;
}
int main() {
    QueueNode * queue,*top,*rear;
    queue=top=rear=initQueue();//创建头结点
    //向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
    rear=enQueue(rear, 1);
    rear=enQueue(rear, 2);
    rear=enQueue(rear, 3);
    rear=enQueue(rear, 4);
    //入队完成，所有数据元素开始出队列
    rear=DeQueue(top, rear);
    rear=DeQueue(top, rear);
    rear=DeQueue(top, rear);
    rear=DeQueue(top, rear);
    rear=DeQueue(top, rear);
    return 0;
}