typedef struct {
    int val;
    struct Node* next;
} Node;

typedef struct{
    Node* front;
    Node * rear;
}MaxQueue;

MaxQueue* maxQueueCreate() {
    MaxQueue* obj = (MaxQueue*)malloc(sizeof(MaxQueue));
    obj->front = obj->rear = NULL;
    return obj;
}

int maxQueueMax_value(MaxQueue* obj) {
    if(obj->front == NULL){
        return -1;
    }
    Node* p = obj->front;
    int max = p->val;
    while(p){
        if(p->val > max) max = p->val;
        p = p->next;
    }
    return max;

}

void maxQueuePush_back(MaxQueue* obj, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    if(obj->front == NULL){
        obj->front = newNode;
        obj->rear = newNode;
    }else{
        obj->rear->next = newNode;
        obj->rear = newNode;
    }

}

int maxQueuePop_front(MaxQueue* obj) {
    if(obj->front == NULL) return -1;
    Node *del = obj->front;
    int tmp = del->val;
    obj->front = del->next;
    del->next = NULL;
    free(del);
    return tmp;

}

void maxQueueFree(MaxQueue* obj) {
    Node* p = obj->front;
    while(p){
        Node* del = p;
        p = p->next;
        free(del);
    }
}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/