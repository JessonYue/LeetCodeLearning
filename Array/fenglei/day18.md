```
面试题59 - II. 队列的最大值
难度 中等
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：
输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]

示例 2：
输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 
限制：
1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5

```



### C

```c
//
// Created by 丰雷 on 2020/6/19.
//
#include <stdio.h>
#include <mm_malloc.h>

typedef int data;
typedef struct Node {
    data value;
    struct Node *next;

} Node;

typedef struct {
    struct Node *front;
    struct Node *rear;
} MaxQueue;

MaxQueue *maxQueueCreate() {
    MaxQueue *queue = malloc(sizeof(MaxQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

int maxQueueMax_value(MaxQueue *obj) {
    int data = -1;
    struct Node *node = obj->front;
    while (node != NULL) {
        data = node->value > data ? node->value : data;
        node = node->next;
    }
    return data;
}

void maxQueuePush_back(MaxQueue *obj, int value) {
    struct Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    if (obj->rear == NULL) {
        obj->front = node;
        obj->rear = node;
    } else {
        obj->rear->next = node;
        obj->rear = node;
    }
}

int maxQueuePop_front(MaxQueue *obj) {
    struct Node *node = obj->front;
    if (obj->front == obj->rear) {
        // 只有一个值
        obj->front == NULL;
        obj->rear == NULL;
    } else {
        obj->front = obj->front->next;
        free(node);
    }
    return node == NULL ? -1 : node->value;
}

void maxQueueFree(MaxQueue *obj) {
    struct Node *node;
    while (obj->front == NULL && obj->rear == NULL) {
        node = obj->front;
        obj->front = obj->front->next;
        free(node);
    }
}

void maxQueuePrint(MaxQueue *obj) {
    struct Node *node;
    node = obj->front;
    while (node != NULL) {
        printf("data = %d \n", node->value);
        node = node->next;
    }
}


int main() {
    struct MaxQueue *queue = maxQueueCreate();
    maxQueuePush_back(queue,1);
    maxQueuePush_back(queue,2);
    printf("max = %d\n",maxQueueMax_value(queue));
    printf("pop = %d\n",maxQueuePop_front(queue));
    printf("max = %d\n",maxQueueMax_value(queue));
    maxQueuePrint(queue);
    return 0;
}

```





### Java

```java
   
	/**
		思路 维护一个最大值队列，
		从队尾开始，依次比较队列中的数，将小于插入数的数全部清除
	*/ 

		private LinkedList<Integer> data;
    private LinkedList<Integer> maxQue;

    public MaxQueue () {
        data = new LinkedList<>();
        maxQue = new LinkedList<>();
        maxQue.addLast(Integer.MIN_VALUE);
    }

    public int max_value () {
        if (data.isEmpty()) {
            return -1;
        }
        return maxQue.peekFirst();
    }

    public void push_back (int value) {
        data.addLast(value);
        while (!maxQue.isEmpty() && maxQue.peekLast() < value) {
            maxQue.removeLast();
        }
        maxQue.addLast(value);
    }

    public int pop_front () {
        if (data.isEmpty()) return -1;
        int front = data.removeFirst();
        if (maxQue.peekFirst() == front) {
            maxQue.removeFirst();
        }
        return front;
    }

```



### Kotlin

```ko
class MyQueue {

    var data: LinkedList<Int> = LinkedList()
    var maxList: LinkedList<Int> = LinkedList()

    fun max_value(): Int {
        if (data.isEmpty()){
            return -1
        }
        return maxList.peekFirst()
    }

    fun push_back(value: Int) {
        data.addLast(value);
        while (!maxList.isEmpty() && maxList.peekLast() < value) {
            maxList.removeLast();
        }
        maxList.add(value)
    }

    fun pop_front(): Int {
        if (data.isEmpty()) return -1
        var front = data.pollFirst()
        if (front == maxList.peekFirst()) maxList.removeFirst()
        return front;
    }

}
```

