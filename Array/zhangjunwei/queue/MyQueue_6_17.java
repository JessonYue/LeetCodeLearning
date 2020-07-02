package com.lanfairy.md.queue;

import java.util.Iterator;
import java.util.Stack;

public class MyQueue {
    /**
     * Initialize your data structure here.
     */
    private Stack<Integer> enqueue;
    private Stack<Integer> dequeue;

    public MyQueue() {
        enqueue = new Stack<>();
        dequeue = new Stack<>();
    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
        enqueue.push(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        if (enqueue.isEmpty()) return -1;
        while (!enqueue.isEmpty()) {
            dequeue.push(enqueue.pop());
        }
        int res = dequeue.pop().intValue();
        while (!dequeue.isEmpty()) {
            enqueue.push(dequeue.pop());
        }
        return res;
    }

    /**
     * Get the front element.
     */
    public int peek() {
        if (enqueue.isEmpty()) return -1;
        while (!enqueue.isEmpty()) {
            dequeue.push(enqueue.pop());
        }
        int res = dequeue.peek();
        while (!dequeue.isEmpty()){
            enqueue.push(dequeue.pop());
        }
        return res;
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return enqueue.isEmpty();
    }


    public static void main(String[] args) {
        MyQueue obj = new MyQueue();
        obj.push(2);
        obj.push(1);
        int param_3 = obj.peek();
        int param_2 = obj.pop();
        boolean param_4 = obj.empty();
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
