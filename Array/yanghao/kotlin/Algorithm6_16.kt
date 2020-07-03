package staudy

import java.util.*

class Algorithm6_16 {

    /** Initialize your data structure here. */
    private val stack = Stack<Int>()
    private val stackTwo = Stack<Int>()
    var tail:Int = 0

    /** Push element x to the back of queue. */
    fun push(x: Int) {
        stack.push(x)
    }

    /** Removes the element from in front of queue and returns that element. */
    fun pop(): Int {
        stackTwo.clear()
        stack.forEachIndexed {index,it ->
            if(index == 0) {
                tail = it
                return@forEachIndexed
            } else {
                stackTwo.push(it)
            }
        }
        stack.clear()
        stackTwo.forEach {
            stack.push(it)
        }
        return tail
    }

    /** Get the front element. */
    fun peek(): Int {
        tail = stack[0]
        return tail
    }

    /** Returns whether the queue is empty. */
    fun empty(): Boolean {
        return stack.isEmpty()
    }
}

fun main(args: Array<String>) {
    val a = Algorithm6_16()
    a.push(1)
    a.push(2)
    println(a.peek())
    println(a.pop())
    println(a.pop())
    println(a.empty())
}