package com.hlg.daydaytobusiness
import java.util.*

fun main() {
    val obj = MyStack()
    obj.push(3)
    val param_2 = obj.pop()
    val param_3 = obj.top()
    val param_4 = obj.empty()
}

internal class MyStack {

    var que: Queue<Int>

    /** Initialize your data structure here.  */
    init {
        que = LinkedList<Int>()
    }

    /** Push element x onto stack.  */
    fun push(x: Int) {
        que.add(x)
        for (i in 0 until que.size - 1)
            que.add(que.poll())
    }

    /** Removes the element on top of the stack and returns that element.  */
    fun pop(): Int {
        return que.poll()
    }

    /** Get the top element.  */
    fun top(): Int {
        return que.peek()
    }

    /** Returns whether the stack is empty.  */
    fun empty(): Boolean {
        return que.size == 0
    }
}