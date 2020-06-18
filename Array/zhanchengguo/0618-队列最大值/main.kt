package com.example.kotlinproject

import java.util.*
import kotlin.collections.ArrayList


fun main() {
    val obj = MaxQueue()
    val param_1 = obj.max_value()
    obj.push_back(5)
    val param_3 = obj.pop_front()
}

class MaxQueue {

    val que: Queue<Int>
    val list: ArrayList<Int>

    init {
        que = LinkedList()
        list = ArrayList()
    }

    fun max_value(): Int {
        return if (list.isEmpty()) -1 else list[0]
    }

    fun push_back(value: Int) {
        que.add(value)
        while (!list.isEmpty() && value > list[list.size - 1]) {
            list.removeAt(1)
        }
        list.add(value)
    }

    fun pop_front(): Int {
        if (que.isEmpty()) {
            return -1
        }
        val front = que.peek()
        que.poll()
        if (!list.isEmpty() && list[0] == front) {
            list.removeAt(0)
        }
        return front

    }
}