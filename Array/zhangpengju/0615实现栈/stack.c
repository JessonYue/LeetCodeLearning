typedef struct listNode {
    struct ListNode *next;
    int val;
} ListNode;

typedef struct {
    ListNode *tail;
    ListNode *head;
} Queues;

typedef struct {
    Queues *q1;
} MyStack;





MyStack* myStackCreate() {
    MyStack *myStack = (MyStack *)malloc(sizeof(MyStack));
    myStack->q1 = (Queues *)malloc(sizeof(Queues));
    myStack->q1->tail = NULL;
    myStack->q1->head = NULL;
    return myStack;
}


void myStackPush(MyStack* obj, int x) {
    ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
    tmp->val = x;
    tmp->next = NULL;
    if (obj->q1->tail == NULL) {
        obj->q1->head = obj->q1->tail = tmp;
    } else {
        obj->q1->head->next = tmp;
        obj->q1->head = obj->q1->head->next;
    }
    while (obj->q1->tail != tmp) {
        obj->q1->head->next = obj->q1->tail;
        obj->q1->head = obj->q1->tail;
        obj->q1->tail = obj->q1->tail->next;
    }
    obj->q1->head->next = NULL;
}


int myStackPop(MyStack* obj) {
    ListNode *tmp = obj->q1->tail;
    obj->q1->tail = obj->q1->tail->next;
    int data = tmp->val;
    free(tmp);
    return data;
}


int myStackTop(MyStack* obj) {
    return obj->q1->tail->val;
}


bool myStackEmpty(MyStack* obj) {
    if (obj->q1->tail == NULL) {
        return true;
    } else {
        return false;
    }
}

void myStackFree(MyStack* obj) {
    while (obj->q1->tail != NULL) {
        ListNode *tmp = obj->q1->tail;
        obj->q1->tail = obj->q1->tail->next;
        free(tmp);
    }
}
