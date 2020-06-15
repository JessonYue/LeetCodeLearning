typedef struct myLinkNode {
    int val;
    struct myLinkNode* next;
}LinkNode;

typedef struct {
    LinkNode* top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* myStack = calloc(1, sizeof(MyStack));
    return myStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    LinkNode* newNode = malloc(sizeof(LinkNode));
    newNode->val = x;
    newNode->next = obj->top;
    obj->top = newNode;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(!obj || !(obj->top)) return -1;
    int val = obj->top->val;
    LinkNode* delNode = obj->top;
    obj->top = obj->top->next;
    free(delNode);
    return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->top->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj) {
        if(obj->top) return false;
    }
    return true;
}

void myStackFree(MyStack* obj) {
    if(obj && obj->top) {
        myStackPop(obj);
    }
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/