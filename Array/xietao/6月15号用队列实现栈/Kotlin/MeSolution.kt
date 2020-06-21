package xt

import java.util.*

class MeSolution {
    var tail = 0
    val q: Queue<Int>
    fun push(x: Int) {
        tail = x
        q.add(x)
    }

    fun pop(): Int {
        val size = q.size
        for (i in 0 until size - 2) {
            q.add(q.remove())
        }
        tail = q.remove()
        q.add(tail)
        return q.remove()
    }

    fun top(): Int {
        return tail
    }

    fun empty(): Boolean {
        return q.isEmpty()
    }

    init {
        q = LinkedList()
    }
}