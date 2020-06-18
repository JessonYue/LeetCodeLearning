package com.example.admin.myapplication.stack

import java.util.*

/**
 *create by yx
 *on 2020/6/17
 */
class MyQueueKotlin {

    private val stack1: Stack<Int> = Stack()
    private val stack2: Stack<Int> = Stack()

    /** Push element x to the back of queue. */
    fun push(x: Int) {
        stack1.push(x)
    }

    /** Removes the element from in front of queue and returns that element. */
    fun pop(): Int {
        if (stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.pop())
            }
        }

        return stack2.pop()
    }

    /** Get the front element. */
    fun peek(): Int {
        if (stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.pop())
            }
        }

        return stack2.peek()
    }

    /** Returns whether the queue is empty. */
    fun empty(): Boolean {
        return stack1.empty() && stack2.empty()
    }
}