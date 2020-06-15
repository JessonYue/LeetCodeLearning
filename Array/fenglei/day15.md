```
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```



### C

```c
#include <stdbool.h>
#include <mm_malloc.h>

typedef int data;

typedef struct Node {
    data value;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} MyStack;

/** Initialize your data structure here. */

MyStack *myStackCreate() {
    MyStack *stack = calloc(1, sizeof(MyStack));
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack *obj, int x) {
    Node *node = malloc(sizeof(Node));
    node->value = x;
    node->next = obj->top;
    obj->top = node;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack *obj) {
    Node *node = obj->top;
    int value = node->value;
    obj->top = node->next;
    free(node);
    return value;
}

/** Get the top element. */
int myStackTop(MyStack *obj) {
    return obj->top->value;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack *obj) {
    return obj->top == NULL;
}

void myStackFree(MyStack *obj) {
    while (obj->top){
        Node *node = obj->top;
        obj->top = node->next;
        free(node);
    }
    free(obj);
}

```



### Java

```java
public class MyStack {

    private Node top;
    private int size = 0;
    /**
     * Initialize your data structure here.
     */
    public MyStack () {
    }

    /**
     * Push element x onto stack.
     */
    public void push (int x) {
        Node n = new Node(x);
        n.next = top;
        top = n;
        size++;
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop () {
        int value = top.value;
        top = top.next;
        size--;
        return value;
    }

    /**
     * Get the top element.
     */
    public int top () {
        return top.value;
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty () {
        return size == 0;
    }


    private class Node {
        Node next;
        int value;

        public Node (int value) {
            this.value = value;
            this.next = null;
        }
    }
}
```



### Kotlin

```ko
class MyStack() {

    /** Initialize your data structure here. */
    private var top: Node? = null
    private var size:Int = 0;

    /** Push element x onto stack. */
    fun push(x: Int) {
        val node = Node(x)
        node.next = top
        top = node
        size++
    }

    /** Removes the element on top of the stack and returns that element. */
    fun pop(): Int {
       val value = top!!.value
        top = top!!.next
        size--
        return value;
    }
    
    /** Get the top element. */
    fun top(): Int {
        return top!!.value
    }

    /** Returns whether the stack is empty. */
    fun empty(): Boolean {
        return size == 0
    }


    class Node(var value: Int) {
        var next: Node? = null
        init {
            this.next = null
        }
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
```

