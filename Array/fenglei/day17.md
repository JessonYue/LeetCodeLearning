```
实现一个MyQueue类，该类用两个栈来实现一个队列。


示例：

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false

说明：

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```



### C++

```c++
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>s1,s2;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};


int main() {

    auto *queue = new MyQueue();
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);
    queue->push(5);

    while (!empty()) {
        int data = queue->a->pop();
        printf("data = %d\n", data);
    }
    return 0;
}


// 打印结果
data = 1
data = 2
data = 3
data = 4
data = 5
```





### Java

```java
public class MyQueue {

    private Stack<Integer> a;
    private Stack<Integer> b;

    /**
     * Initialize your data structure here.
     */
    public MyQueue () {
        a = new Stack<>();
        b = new Stack<>();
    }

    /**
     * Push element x to the back of queue.
     */
    public void push (int x) {
        while (!a.empty()) {
            int data = a.pop();
            b.push(data);
        }
        b.push(x);
        while (!b.empty()) {
            int data = b.pop();
            a.push(data);
        }
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop () {
        return a.pop();
    }

    /**
     * Get the front element.
     */
    public int peek () {
        return a.peek();
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty () {
        return a.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```





### Kotlin

```ko

```

