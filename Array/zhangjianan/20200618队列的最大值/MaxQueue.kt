package com.example.testapplication

import java.util.*

class MaxQueue {
    var queue: Queue<Int> = LinkedList()
    var deque: Deque<Int> = LinkedList()
    fun max_value(): Int {
        return if (deque.size > 0) deque.peek() else -1
    }

    fun push_back(value: Int) {
        queue.offer(value)
        while (deque.size > 0 && deque.peekLast() < value) {
            deque.pollLast()
        }
        deque.offerLast(value)
    }

    fun pop_front(): Int {
        val temp = if (queue.size > 0) queue.poll() else -1
        if (deque.size > 0 && temp == deque.peek()) {
            deque.poll()
        }
        return temp
    }

}