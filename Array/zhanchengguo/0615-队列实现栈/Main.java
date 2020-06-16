package com.hlg.daydaytobusiness;

import java.util.LinkedList;
import java.util.Queue;

public class Main {

    void main() {
        MyStack obj = new MyStack();
        obj.push(3);
        int param_2 = obj.pop();
        int param_3 = obj.top();
        boolean param_4 = obj.empty();
    }
}

class MyStack {

    Queue<Integer> que;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
        que = new LinkedList<Integer>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        que.add(x);
        for (int i = 0; i < que.size() - 1; i++) {
            que.add(que.poll());
        }
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        return que.poll();
    }

    /**
     * Get the top element.
     */
    public int top() {
        return que.peek();
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return que.size() == 0;
    }
}

