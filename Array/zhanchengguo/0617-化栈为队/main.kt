package com.hlg.daydaytobusiness

import java.util.*

fun main() {
    val obj = MyQueue()
    obj.push(6)
    val param_2 = obj.pop()
    val param_3 = obj.peek()
    val param_4 = obj.empty()
}

class MyQueue {

    private val st1: Stack<Int>
    private val st2: Stack<Int>

    /**
     * Initialize your data structure here.
     */
    init {
        st1 = Stack()
        st2 = Stack()
    }

    /**
     * Push element x to the back of queue.
     */
    fun push(x: Int) {
        st1.push(x)
    }

    fun pop(): Int {
        val value = peek()
        st2.pop()
        return value
    }

    /**
     * Get the front element.
     */
    fun peek(): Int {
        if (st2.empty()) {
            while (!st1.empty()) {
                val value = st1.pop()
                st2.push(value)
            }
        }
        return st2.peek()
    }

    /**
     * Returns whether the queue is empty.
     */
    fun empty(): Boolean {
        return st1.empty() && st2.empty();
    }
}
