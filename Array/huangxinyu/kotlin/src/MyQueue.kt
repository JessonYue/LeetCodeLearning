import java.util.*

class MyQueue {
    val stack1: Stack<Int> = Stack<Int>()
    val stack2: Stack<Int> = Stack<Int>()
    fun push(x: Int) {
        stack1.push(x)
    }

    fun peek(): Int {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                val peek = stack1.peek()
                stack2.push(peek)
                stack1.pop()
            }
        }
        return stack2.peek()
    }

    fun pop(): Int {
        val top = peek()
        stack2.pop()
        return top
    }

    fun empty(): Boolean {
        return stack1.empty() && stack2.empty()
    }
}