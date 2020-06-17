#define MAXSIZE 30

typedef struct Stack {
    int top;
    int data[MAXSIZE];
} Stack;

typedef struct {
    Stack* inStack;
    Stack* outStack;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* myQueue = (MyQueue*)malloc(sizeof(MyQueue));
    myQueue->inStack = (Stack*)malloc(sizeof(Stack));
    myQueue->outStack = (Stack*)malloc(sizeof(Stack));
    myQueue->inStack->top = -1;
    myQueue->outStack->top = -1;
    return myQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if(!obj) return;
    if(obj->inStack->top < MAXSIZE-1){
        obj->inStack->top = obj->inStack->top + 1;
        obj->inStack->data[obj->inStack->top] = x;
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(!obj) return -1;
    if(obj->outStack->top < 0) {
        if(obj->inStack->top < 0) {
            return -1;
        } else {
            int size = obj->inStack->top;
            for(int i = size; i > -1 ; i--) {
                obj->outStack->data[size - i] = obj->inStack->data[i];
                obj->inStack->data[i] = 0;
            }
            obj->outStack->top = size;
            obj->inStack->top = -1;
        }
    }
    int ret = obj->outStack->data[obj->outStack->top];
    obj->outStack->data[obj->outStack->top] = 0;
    obj->outStack->top --;
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(!obj) return -1;
    if(obj->outStack->top < 0) {
        if(obj->inStack->top < 0) {
            return -1;
        } else {
            int size = obj->inStack->top;
            for(int i = size; i > -1 ; i--) {
                obj->outStack->data[size - i] = obj->inStack->data[i];
                obj->inStack->data[i] = 0;
            }
            obj->outStack->top = size;
            obj->inStack->top = -1;
        }
    }
    return obj->outStack->data[obj->outStack->top];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->outStack->top < 0 && obj->inStack->top < 0) return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    if(!obj) return;
    free(obj->inStack);
    free(obj->outStack);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/