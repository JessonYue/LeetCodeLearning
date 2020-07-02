package com.example.admin.myapplication.stack

import java.util.*

/**
 * create by yx
 * on 2020/6/18
 * 面试题59 - II. 队列的最大值
 * 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 * <p>
 * 若队列为空，pop_front 和 max_value 需要返回 -1
 * <p>
 * 这个题里如果用栈来保存最大值，就必须考虑队列弹出时，栈也要把相应的值弹出，栈的弹出方式跟队列不同，所以会比较麻烦。
 * 好的办法是用队列来保存最大值，然后用同样的弹出方式来弹出数据
 */
class MaxQueueKotlin {

    val queue: Queue<Int> = LinkedList()
    val maxQueue: LinkedList<Int> = LinkedList()

    //队列先进先出，所以队头的值应该最大
    fun max_value(): Int {
        if (queue.isEmpty()) {
            return -1
        }

        return maxQueue.first
    }

    fun push_back(value: Int) {
        queue.offer(value)
        //从队尾开移除比目标值小的无用值,这里应该不能使用等于防止多个重复值情况
        while (maxQueue.isNotEmpty() && maxQueue.last < value) {
            maxQueue.removeLast()
        }
        maxQueue.offer(value)
    }

    fun pop_front(): Int {
        if (queue.isEmpty()) {
            return -1
        }
        val result = queue.poll()
        if (maxQueue.first == result) {
            maxQueue.poll()
        }

        return result
    }
}