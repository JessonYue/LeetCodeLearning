package com.hlg.daydaytobusiness;

import java.util.Stack;

public class Main {

    void main() {
        MyQueue obj = new MyQueue();
        obj.push(6);
        int param_2 = obj.pop();
        int param_3 = obj.peek();
        boolean param_4 = obj.empty();
    }
}

class MyQueue {

    private Stack<Integer> st1, st2;

    /**
     * Initialize your data structure here.
     */
    public MyQueue() {
        st1 = new Stack<>();
        st2 = new Stack<>();
    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
        st1.push(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        int value = peek();
        st2.pop();
        return value;
    }

    /**
     * Get the front element.
     */
    public int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                int value = st1.pop();
                st2.push(value);
            }
        }
        return st2.peek();
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return st1.empty() && st2.empty();
    }
}
