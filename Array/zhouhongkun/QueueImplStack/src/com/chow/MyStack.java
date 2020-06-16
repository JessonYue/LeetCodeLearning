package com.chow;

import java.util.LinkedList;
import java.util.Queue;

public class MyStack {

    Queue<Integer> myQueue;

    /** Initialize your data structure here. */
    public MyStack() {
        myQueue = new LinkedList<>();
    }

    /** Push element x onto stack.
     * 每次加入新元素时，都把除队尾的其它元素出队再入队
     * 这样就相当于是最新入队的元素是在队头了
     */
    public void push(int x) {
        myQueue.add(x);
        int size = myQueue.size();
        for(int i=0; i<size-1; i++){
            myQueue.add(myQueue.peek());
            myQueue.remove();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int element = myQueue.poll();
        return element;
    }

    /** Get the top element. */
    public int top() {
        if(empty()){
            return -1;
        }
        return myQueue.peek();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return myQueue.isEmpty();
    }

    public int size(){
        return myQueue.isEmpty() ? -1 : myQueue.size();
    }
}
