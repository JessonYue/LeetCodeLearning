package com.test

import java.util.Stack

internal object MyQueue {
    @JvmStatic
    fun main(args: Array<String>) {
        val obj = MyQueue1()
        obj.push(1)
        obj.push(2)
        val param_3 = obj.peek()
        val param_2 = obj.pop()
        val param_4 = obj.empty()
        println(param_2)
        println(param_3)
        println(param_4)
    }

    /**
     * Initialize your data structure here.
     */
    internal class MyQueue1 {
        var stack = Stack<Int>()
        var stack1 = Stack<Int>()

        /**
         * Push element x to the back of queue.
         */
        fun push(x: Int) {
            stack.push(x)
        }

        /**
         * Removes the element from in front of queue and returns that element.
         */
        fun pop(): Int {
            while (!stack.empty()) {
                stack1.push(stack.pop())
            }
            val pop = stack1.pop()
            while (!stack1.empty()) {
                stack.push(stack1.pop())
            }
            return pop!!
        }

        /**
         * Get the front element.
         */
        fun peek(): Int {
            while (!stack.empty()) {
                stack1.push(stack.pop())
            }
            val peek = stack1.peek()
            while (!stack1.empty()) {
                stack.push(stack1.pop())
            }
            return peek!!
        }

        /**
         * Returns whether the queue is empty.
         */
        fun empty(): Boolean {
            return stack.empty()
        }
    }
}
