package LInterview03_04

import java.util.*

class KMyQueue {
    private val stack1 = Stack<Int>()
    private val stack2 = Stack<Int>()

    fun pop(): Int {
        while (stack1.size > 1) {
            stack2.push(stack1.pop())
        }
        val pop = stack1.pop()
        while (!stack2.isEmpty()) {

            stack1.push(stack2.pop())
        }
        return pop
    }

    fun peek(): Int {
        while (stack1.size > 1) {
            stack2.push(stack1.pop())
        }
        val pop = stack1.pop()
        stack1.push(pop)
        while (!stack2.isEmpty()) {

            stack1.push(stack2.pop())
        }
        return pop
    }

    fun empty(): Boolean = stack1.isEmpty()
}