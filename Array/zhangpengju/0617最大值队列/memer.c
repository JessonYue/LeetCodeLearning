//
// Created by 张鹏举 on 2020-06-18.
//

//内存管理
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//实现队列
typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct MaxQueue{//使用链表实现队列
   struct Node* head;
   struct Node* foot;
   struct MaxQueue* dequ;//存储最大值 ，从大到小，在入队时，按照比较规则存入
} MaxQueue;


MaxQueue* maxQueueCreate() {
    return malloc(sizeof(MaxQueue));
}

int maxQueueMax_value(MaxQueue* obj) {
    MaxQueue* deq =obj->dequ;
    Node* node =  deq->head;
    return node->val;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    //倒着放
    if(obj->head == NULL){
        obj->head->next = newNode;
        obj->foot = obj->head;
        obj->dequ = malloc(sizeof(MaxQueue));//初始化
        obj->dequ->head = obj->head;
        obj->dequ->foot = obj->head;
        obj->dequ->dequ = NULL;
        return;
    }

    obj->foot->next = newNode;
    obj->foot = newNode;

    //执行dequ 比较入队
    //和队头比较，往后依次比较，发现大于某个节点，直接插入，并将该节点后边整体移除断掉

    MaxQueue* dequeue = obj->dequ;
    Node* temp = dequeue->head;
    Node* parent = NULL;
    while(temp){
        if(value > temp->val){//进行入队
            if(parent != NULL){
               parent->next = newNode;
            }else{//
               dequeue->head = newNode;
            }
        }else{
            dequeue->foot->next = newNode;
            dequeue->foot = newNode;
        }

        parent = temp;
        temp = temp->next;
    }
}

int maxQueuePop_front(MaxQueue* obj) {
    Node* newHead =  obj->head->next;


    Node* pop = obj->head;
    obj->head = newHead;//取出第一个node

    if(newHead == NULL){//判断取空问题
        obj->foot = obj->head;
    }

    //去比较dequ 要不要出队列
    Node* maxNode = obj->dequ->head;
    if(pop->val == maxNode->val){
        Node* he = obj->dequ->head;
        obj->dequ->head = he->next;
        he->next = NULL;
    }

    pop->next = NULL;
    free(pop);

}

void maxQueueFree(MaxQueue* obj) {
     Node* temp = obj->head;

     while(temp != NULL){
        Node* next = temp->next;
        temp->next = NULL;

        if(temp == obj->dequ->head){
           Node* dequHead = obj->dequ->head;
           Node* no = dequHead->next;
           obj->dequ->head = no;

           dequHead->next = NULL;
        }


        free(temp);
        temp = next;
     }
}
