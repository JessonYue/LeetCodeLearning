package com.lanfairy.md;

import java.util.LinkedList;

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
public class MyStack {
    private LinkedList<Integer> stack;
    /** Initialize your data structure here. */
    public MyStack() {
        stack = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        stack.offerFirst(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if (empty())return -1;
        return stack.pollFirst().intValue();
    }

    /** Get the top element. */
    public int top() {
        if (empty())return -1;
       return stack.peekFirst().intValue();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return stack.isEmpty();
    }
}
