package com.example.admin.myapplication

import java.util.*
import kotlin.properties.Delegates

/**
 *create by yx
 *on 2020/6/15
 * 参考网上思路，改成单链表实现
 */
class MyStack {
    val deque: LinkedList<Int> = LinkedList()
    var tail by Delegates.notNull<Int>()

    /** Initialize your data structure here. */


    /** Push element x onto stack. */
    fun push(x: Int) {
        deque.add(x)
        tail = x
    }

    /** Removes the element on top of the stack and returns that element. */
    fun pop(): Int {
        var size = deque.size
        while (size > 1) {
            size--
            tail = deque.pop()
            deque.add(tail)
        }
        return deque.pop()
    }

    /** Get the top element. */
    fun top(): Int {
        return tail
    }

    /** Returns whether the stack is empty. */
    fun empty(): Boolean {
        return deque.isEmpty()
    }

}