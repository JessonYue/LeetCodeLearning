package staudy

import java.util.*

class Algorithm6_14{

    private val stack:Queue<Int> = LinkedList<Int>()
    var tail:Int = 0;

    fun push(x: Int) {
        tail = x
        stack.add(x)
    }

    /** Removes the element on top of the stack and returns that element. */
    fun pop(): Int {
        repeat(stack.size) {
            stack.add(stack.remove())
        }
        tail = stack.remove()
        stack.add(tail)
        return stack.remove()
    }

    /** Get the top element. */
    fun top(): Int {
        return tail
    }

    /** Returns whether the stack is empty. */
    fun empty(): Boolean {
        return stack.isEmpty()
    }
}

fun main(args: Array<String>) {

}