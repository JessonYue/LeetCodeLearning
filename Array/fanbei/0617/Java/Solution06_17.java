package com.example.computerdemo;

import java.util.Stack;

public class Solution06_17 {
    class MyQueue {
        Stack<Integer> stackWrite;
        Stack<Integer> stackRead;

        /**
         * Initialize your data structure here.
         */
        public MyQueue() {
            stackWrite = new Stack<Integer>();
            stackRead = new Stack<Integer>();
        }

        /**
         * Push element x to the back of queue.
         */
        public void push(int x) {
            stackWrite.push(x);
        }

        /**
         * Removes the element from in front of queue and returns that element.
         */
        public int pop() {
            peek();
            return stackRead.pop();
        }

        /**
         * Get the front element.
         */
        public int peek() {
            if (!stackRead.isEmpty()) {
                return stackRead.peek();
            }
            while (!stackWrite.isEmpty()) {
                stackRead.push(stackWrite.pop());
            }
            return stackRead.peek();
        }

        /**
         * Returns whether the queue is empty.
         */
        public boolean empty() {
            return stackWrite.isEmpty() && stackRead.isEmpty();
        }
    }

}
