//
// Created by LCX on 2020/6/17.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define MAX_SIZE 5

typedef struct {
    int Data[MAX_SIZE];
    int top;
}MyStack;


typedef struct {
    MyStack myStack1;
    MyStack myStack2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->myStack1.top = -1;
    queue->myStack2.top = -1;
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if(obj->myStack1.top < MAX_SIZE-1){
        obj->myStack1.Data[++obj->myStack1.top] = x;
    }else{
        printf("the stack if full");
        return;
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(obj->myStack2.top == -1){
        if(obj->myStack1.top != -1){   //
            while (obj->myStack1.top != -1)
            {
                obj->myStack2.Data[++obj->myStack2.top] = obj->myStack1.Data[obj->myStack1.top--];
            }
            return obj->myStack2.Data[obj->myStack2.top--];
        }
        else{
            return -1;
        }
    }else{
        return obj->myStack2.Data[obj->myStack2.top--];
    }
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(obj->myStack2.top == -1){
        if(obj->myStack1.top != -1){   //
            while (obj->myStack1.top != -1)
            {
                obj->myStack2.Data[++obj->myStack2.top] = obj->myStack1.Data[obj->myStack1.top--];
            }
            return obj->myStack2.Data[obj->myStack2.top];
        }
        else{
            return -1;
        }
    }else{
        return obj->myStack2.Data[obj->myStack2.top];
    }
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->myStack1.top == -1 && obj->myStack2.top == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}


int main()
{
    MyQueue *myQueue = myQueueCreate();
    myQueuePush(myQueue,1);
    myQueuePush(myQueue,2);
    myQueuePush(myQueue,3);
    myQueuePush(myQueue,4);
    myQueuePush(myQueue,5);
    if(myQueueEmpty(myQueue)){
        printf("kong1\n");
    }else{
        printf("fei1\n");
    }
    printf("queue = %d\n",myQueuePop(myQueue));
    printf("queue = %d\n",myQueuePop(myQueue));
    printf("queue = %d\n",myQueuePop(myQueue));
    printf("queue = %d\n",myQueuePop(myQueue));
    printf("queue = %d\n",myQueuePeek(myQueue));
    printf("queue = %d\n",myQueuePop(myQueue));
    if(myQueueEmpty(myQueue)){
        printf("kong2\n");
    }else{
        printf("fei2\n");
    }
    return 0;
}

