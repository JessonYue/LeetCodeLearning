package L225

import java.util.*

class KMyStack {
    private var queue1: Queue<Int> = LinkedList()
    private var queue2: Queue<Int> = LinkedList()

    var top: Int = 0

    fun push(x: Int) {
        queue1.add(x)
        top = x
    }

    fun pop(): Int? {
        if (queue1.isEmpty()) {
            throw IllegalAccessException("pop stack is empty!")
        }

        if (queue1.size > 1) {
            val remove = queue1.remove()
            queue2.add(remove)
        }
        val remove = queue1.remove()
        val temp: Queue<Int> = queue1
        queue1 = queue2
        queue2 = temp
        return remove
    }

    fun top(): Int = if (empty())
        throw IllegalAccessException("top stack is empty!")
    else
        top


     fun empty(): Boolean = queue1.isEmpty()
}