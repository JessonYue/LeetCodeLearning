//
// Created by LCX on 2020/6/17.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define MAX_SIZE 10

typedef struct{
    int DATA[MAX_SIZE];
    int TOP;
}MyStack;


typedef struct {
    MyStack mystack1;
    MyStack mystack2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* TempQueue=(MyQueue*)malloc(sizeof(MyQueue));
    TempQueue->mystack1.TOP=-1;
    TempQueue->mystack2.TOP=-1;
    return TempQueue;

}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
//    if(obj->mystack1.TOP < MAX_SIZE){
//        while (obj->mystack1.TOP == -1){
//            obj->mystack2.DATA[++(obj->mystack2.TOP)] = obj->mystack1.DATA[--(obj->mystack1.TOP)];
//        }
//        obj->mystack1.DATA[++(obj->mystack1.TOP)] = x;
//    }

    if(obj->mystack1.TOP<MAX_SIZE){ //栈是否满
        while(obj->mystack1.TOP!=-1){
            obj->mystack2.DATA[++(obj->mystack2.TOP)]=obj->mystack1.DATA[(obj->mystack1.TOP)--];
        }
        obj->mystack1.DATA[++(obj->mystack1.TOP)]=x;
        while(obj->mystack2.TOP!=-1){
            obj->mystack1.DATA[++(obj->mystack1.TOP)]=obj->mystack2.DATA[(obj->mystack2.TOP)--];
        }
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
//    if(obj->mystack2.TOP == -1){
//        while (obj->mystack1.TOP= -1){
//            obj->mystack2.DATA[++(obj->mystack2.TOP)] = obj->mystack1.DATA[--(obj->mystack1.TOP)];
//        }
//        return obj->mystack2.DATA[(obj->mystack2.TOP--)];
//    }
if(obj->mystack1.TOP!=-1)
        return obj->mystack1.DATA[(obj->mystack1.TOP)--];
    return NULL;

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
//    if(obj->mystack2.TOP == -1){
//        while (obj->mystack1.TOP= -1){
//            obj->mystack2.DATA[++(obj->mystack2.TOP)] = obj->mystack1.DATA[--(obj->mystack1.TOP)];
//        }
//        return obj->mystack2.DATA[(obj->mystack2.TOP)];
//    }
if(obj->mystack1.TOP!=-1)
        return obj->mystack1.DATA[obj->mystack1.TOP];
    return NULL;

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
     if(obj->mystack1.TOP==-1)
            return true;
        return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}





int main()
{
    printf("hello");
    return 0;
}