### 用队列实现栈

1. Java

```java
class MyStack {
 private Queue<Integer> q1 = new LinkedList<>();
    private int tail = 0;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {

    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        tail = x;
        q1.add(x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        for (int i = 0; i < q1.size() - 2; i++) {
            q1.add(q1.remove());
        }
        tail = q1.remove();
        q1.add(tail);
        return q1.remove();
    }

    /**
     * Get the top element.
     */
    public int top() {
        return tail;
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return q1.isEmpty();
    }
}
```
2. C++ 

```c++
class MyStack {
public:
  

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size() - 1; i++) {
            que.push(que.front());
            que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = top();
        que.pop();
        return val;
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }

private:
    std::queue<int> que;
};

```
3. KT 

```kotlin
class MyStack() {

    /** Initialize your data structure here. */
    val queue = LinkedList<Int>()
    var tail = 0

    /** Push element x onto stack. */
    fun push(x: Int) {
        tail = x
        queue.add(x)
    }

    /** Removes the element on top of the stack and returns that element. */
    fun pop(): Int {
        for (i in 0 until queue.size - 2) {
            queue.add(queue.remove())
        }
        tail = queue.remove();
        queue.add(tail)
        return queue.remove();
    }

    /** Get the top element. */
    fun top(): Int {
        return tail;
    }

    /** Returns whether the stack is empty. */
    fun empty(): Boolean {
        return queue.isEmpty()
    }
}
```

### 有效的括号

1. Java

```java
    public boolean isValid(String s) {
       Stack<Character> sc = new Stack<>();
        int len = s.length();
        if (len % 2 != 0) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            char c = s.charAt(i);
            switch (c) {
                case '(':
                    sc.push(c);
                    break;
                case '[':
                    sc.push(c);
                    break;
                case '{':
                    sc.push(c);
                    break;
                case ')':
                    if( sc.isEmpty()){
                        return false;
                    }
                    if (sc.pop() != '(')
                        return false;
                    break;
                case ']':
                    if( sc.isEmpty()){
                        return false;
                    }
                    if (sc.pop() != '[')
                        return false;
                    break;
                case '}':
                    if( sc.isEmpty()){
                        return false;
                    }

                    if (sc.pop() != '{')
                        return false;
                    break;
                default:
                    return false;
            }
        }
        return sc.isEmpty();
    }
}
```
2. C++

```c++

```
3. kt

```kotlin
fun isValid(s: String): Boolean {
        val charStack = Stack<Char>()
        for (c in s) {
            if (c == '(') {
                charStack.push(c)
            }
            if (c == '[') {
                charStack.push(c)
            }
            if (c == '{') {
                charStack.push(c)
            }
            if (c == ')') {
                if (charStack.isEmpty()) return false
                if (charStack.peek() != '(') {
                    return false
                }
            }

            if (c == ']') {
                if (charStack.isEmpty()) return false
                if (charStack.peek() != '[') {
                    return false
                }
            }

            if (c == '}') {
                if (charStack.isEmpty()) return false
                if (charStack.peek() != '{') {
                    return false
                }
            }
        }
        return charStack.isEmpty()
    }
```

### 化栈为队
1. Java

```
import java.util.Stack;

public class MyQueue {
    Stack<Integer> stack1;
    Stack<Integer> stack2;

    /**
     * Initialize your data structure here.
     */
    public MyQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
        stack1.push(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
        int res = stack2.pop();
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
        return res;
    }

    /**
     * Get the front element.
     */
    public int peek() {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
        int res = stack2.peek();
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
        return res;
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return stack1.isEmpty();
    }
}
```

2. C++
```

```
3. KT

```kotlin

```