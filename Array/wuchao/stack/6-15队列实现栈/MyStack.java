package com.slow.lib.practice.stack;

import java.util.LinkedList;
import java.util.Queue;

/**
 * @Author wuchao
 * @Date 2020/6/15-9:11 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class MyStack {
    Queue<Integer> queue;
    Queue<Integer> tempQueue;
    int top;
    /** Initialize your data structure here. */
    public MyStack() {
        queue = new LinkedList<>();
        tempQueue = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        queue.add(x);
        top = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(queue.isEmpty()){
            return -1;
        }
        if(queue.size()==1){
            return queue.poll();
        } else {
            while (queue.size()!=1){
                tempQueue.add(queue.poll());
            }
            int popElement = queue.poll();
            while (!tempQueue.isEmpty()){
                queue.add(tempQueue.poll());
            }
            return popElement;
        }
    }

    /** Get the top element. */
    public int top() {
        return top;
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
    }
}
