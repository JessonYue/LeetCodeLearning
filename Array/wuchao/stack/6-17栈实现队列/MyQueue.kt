package com.slow.lib.practice.stack

import java.util.*

/**
 * @Author wuchao
 * @Date 2020/6/17-10:06 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class MyQueue {
    /** Initialize your data structure here. */
    val stack: Stack<Int> = Stack()
    val temp:Stack<Int> = Stack()

    /** Push element x to the back of queue. */
    fun push(x: Int) {
        while(!stack.isEmpty()){
            temp.push(stack.pop())
        }
        stack.push(x)
        while(!temp.isEmpty()){
            stack.push(temp.pop())
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    fun pop(): Int {
        return stack.pop()
    }

    /** Get the front element. */
    fun peek(): Int {
        return stack.peek()
    }

    /** Returns whether the queue is empty. */
    fun empty(): Boolean {
        return stack.isEmpty()
    }
}