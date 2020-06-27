typedef struct LinkList {
    int val;
    struct LinkList *next;
    struct LinkList *prev;
} LinkNode, *LinkPtr;

typedef struct {
    LinkPtr head;
    LinkPtr tail;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *node = (MyStack *)malloc(sizeof(MyStack));
    node->head = (LinkPtr)calloc(1, sizeof(LinkNode));
    node->tail = (LinkPtr)calloc(1, sizeof(LinkNode));
    node->head->next = node->tail;
    node->tail->prev = node->head;
    return node;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    LinkPtr node = (LinkPtr)malloc(sizeof(LinkNode));
    node->val = x;
    obj->tail->prev->next = node;
    node->prev = obj->tail->prev;
    node->next = obj->tail;
    obj->tail->prev = node;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
     LinkPtr node = obj->tail->prev; 
    int val = node->val;
    obj->tail->prev = node->prev;
    node->prev->next = obj->tail;
    free(node);
    return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->tail->prev->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->head->next == obj->tail;
}

void myStackFree(MyStack* obj) {
    while (obj->head) {
        obj->tail = obj->head->next;
        free(obj->head);
        obj->head = obj->tail;
    }
    obj->head = obj->tail = NULL;
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