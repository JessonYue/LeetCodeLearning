typedef struct Node
{
    int val;
    struct Node* next;
}Node;
Node* newNode(int Val)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->val=Val;
    n->next=0;
    return n;
}
void push(Node* Head,int Val)
{
    Node* n=newNode(Val);
    n->next=Head->next;
    Head->next=n;
}
int pop(Node* Head)
{
    Node* n=Head->next;
    Head->next=n->next;
    int result=n->val;
    free(n);
    return result;
}
int peek(Node* Head)
{
    Node* n=Head->next;
    while(n->next!=0)
        n=n->next;
        int result=n->val;
    return result;
}
void del(Node* Head)
{
    while(Head!=0)
    {
        Node* n=Head;
        Head=Head->next;
        free(n);
    }
}
typedef struct {
    Node* stackIn;
    Node* stackOut;
} MyQueue;

bool myQueueEmpty(MyQueue* obj);

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* L=(MyQueue*)malloc(sizeof(MyQueue));
    L->stackIn=newNode(0);
    L->stackOut=newNode(0);
    return L;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
      push(obj->stackIn,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(myQueueEmpty(obj))
      return -1;
if(obj->stackOut->next==0)
        while(obj->stackIn->next!=0)
            push(obj->stackOut,pop(obj->stackIn));
    return (pop(obj->stackOut));
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(myQueueEmpty(obj))
    return -1;
    if(obj->stackOut->next==0)
          return(peek(obj->stackIn));
          return((obj->stackOut->next->val));

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
if(obj->stackOut->next==0&&obj->stackIn->next==0)
        return true;
        return false;
}

void myQueueFree(MyQueue* obj) {
    del(obj->stackIn);
    del(obj->stackOut);
    free(obj);
}
