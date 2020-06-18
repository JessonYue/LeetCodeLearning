package com.test;

import java.util.Stack;

class MyQueue {
    public static void main(String[] args) {
        MyQueue1 obj = new MyQueue1();
        obj.push(1);
        obj.push(2);
        int param_3 = obj.peek();
        int param_2 = obj.pop();
        boolean param_4 = obj.empty();
        System.out.println(param_2);
        System.out.println(param_3);
        System.out.println(param_4);
    }

    static class MyQueue1 {
        Stack<Integer> stack = new Stack<>();
        Stack<Integer> stack1 = new Stack<>();

        /**
         * Initialize your data structure here.
         */
        public MyQueue1() {

        }

        /**
         * Push element x to the back of queue.
         */
        public void push(int x) {
            stack.push(x);
        }

        /**
         * Removes the element from in front of queue and returns that element.
         */
        public int pop() {
            while (!stack.empty()) {
                stack1.push(stack.pop());
            }
            Integer pop = stack1.pop();
            while (!stack1.empty()) {
                stack.push(stack1.pop());
            }
            return pop;
        }

        /**
         * Get the front element.
         */
        public int peek() {
            while (!stack.empty()) {
                stack1.push(stack.pop());
            }
            Integer peek = stack1.peek();
            while (!stack1.empty()) {
                stack.push(stack1.pop());
            }
            return peek;
        }

        /**
         * Returns whether the queue is empty.
         */
        public boolean empty() {
            return  stack.empty();
        }
    }
}
