/**
 *请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 *
 * 若队列为空，pop_front 和 max_value 需要返回 -1
 *
 * 示例 1：
 *
 * 输入:
 * ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
 * [[],[1],[2],[],[],[]]
 * 输出: [null,null,null,2,1,2]
 * 示例 2：
 *
 * 输入:
 * ["MaxQueue","pop_front","max_value"]
 * [[],[],[]]
 * 输出: [null,-1,-1]
 *
 * 限制：
 *
 * 1 <= push_back,pop_front,max_value的总操作数 <= 10000
 * 1 <= value <= 10^5
 *
 */

typedef struct Node{
    int value;
    struct Node* next;
} Node;

Node* createNode(int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

typedef struct {
    Node* head;
    Node* tail;
    int maxValue;
}MaxQueue;

void push_back(MaxQueue *queue, int value){
    Node node = createNode(value);
    if(queue->tail){
        queue->tail->next = node;
    } else{
        queue->head->next = node;
    }
    queue->tail = node;
    if(value > queue->maxValue){
        queue->maxValue = value;
    }
}

int pop_front(MaxQueue *queue){
    Node popNode = queue->head->next;
    int targetNumber = -1;
    if(popNode){
        targetNumber = popNode->value;
        queue->head->next = popNode->next;
        free(popNode);
    }
    return targetNumber;
}


MaxQueue *maxQueueCreate(){
    MaxQueue* maxQueue = malloc(sizeof(MaxQueue));
    maxQueue->head = createNode(-1);
    maxQueue->tail = NULL;
    maxQueue->maxValue = -1;
    return maxQueue;
}

int max_value(MaxQueue *queue){
    return queue->maxValue;
}

