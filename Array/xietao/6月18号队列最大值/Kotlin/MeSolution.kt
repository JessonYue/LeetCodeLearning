package xt

import java.util.*

class MeSolution4 {
    var queue: Queue<Int>
    var maxValue = 0
    fun max_value(): Int {
        return if (queue.isEmpty()) -1 else maxValue
    }

    fun push_back(value: Int) {
        queue.offer(value)
        if (value > maxValue) maxValue = value
    }

    fun pop_front(): Int {
        if (queue.isEmpty()) return -1
        val ans = queue.poll()
        if (ans == maxValue) {
            val size = queue.size
            if (size == 0) {
                maxValue = Int.MIN_VALUE
                return ans
            }
            maxValue = queue.peek()
            for (i in 0 until size) push_back(queue.poll())
        }
        return ans
    }

    init {
        queue = LinkedList<Int>()
    }
}