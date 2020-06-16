package com.android.jcycgj.util

import java.util.*

/**
 * @Author wuchao
 * @Date 2020/6/15-10:06 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class MyStack {
    private lateinit var queue:Queue<Int>
    private lateinit var tempQueue:Queue<Int>
    private var top = -1

    /** Initialize your data structure here. */
    init{
        queue = LinkedList()
        tempQueue = LinkedList()
        top = -1
    }

    /** Push element x onto stack. */
    fun push(x: Int) {
        queue.add(x)
        top = x
    }

    /** Removes the element on top of the stack and returns that element. */
    fun pop(): Int {
        if(queue.isEmpty()){
            return top
        } else {
            return if(queue.size==1){
                top = -1
                queue.poll()
            } else {
                while(queue.size!=1){MyStack.java
                    top = queue.poll()
                    tempQueue.add(top)
                }
                val popElement = queue.poll()
                while(!tempQueue.isEmpty()){
                    queue.add(tempQueue.poll())
                }
                popElement
            }
        }
    }

    /** Get the top element. */
    fun top(): Int {
        return top
    }

    /** Returns whether the stack is empty. */
    fun empty(): Boolean {
        return queue.isEmpty()
    }
}