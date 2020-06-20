import java.util.Stack;

public class Solution_0304 {
    Stack<Integer> wirteStack;
    Stack<Integer> readStack;
    /** Initialize your data structure here. */
    public Solution_0304() {
        wirteStack = new Stack<>();
        readStack = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        wirteStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        peek();
        return readStack.pop();
    }

    /** Get the front element. */
    public int peek() {
        if(!readStack.empty()) {
            return readStack.peek();
        }
        while(!wirteStack.empty()) {
            readStack.push(wirteStack.pop());
        }
        return readStack.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return readStack.empty() && wirteStack.empty();
    }
}
