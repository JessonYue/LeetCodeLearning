package xt

import java.util.*

class MeSolution {
    var stackWrite: Stack<Int>
    var stackRead: Stack<Int>
    fun push(x: Int) {
        stackWrite.push(x)
    }

    fun pop(): Int { //移除栈顶元素
        peek()
        return stackRead.pop()
    }

    fun peek(): Int { //移除栈顶元素但是不删除
        if (!stackRead.isEmpty()) {
            return stackRead.peek()
        }
        while (!stackWrite.isEmpty()) {
            stackRead.push(stackWrite.pop())
        }
        return stackRead.peek()
    }

    /** Returns whether the queue is empty.  */
    fun empty(): Boolean {
        return stackWrite.isEmpty() && stackRead.isEmpty()
    }

    init {
        stackWrite = Stack()
        stackRead = Stack()
    }
}