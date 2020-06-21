package mykotlin

import java.util.*

class MaxQueue() {
    private var queue: LinkedList<Int> = LinkedList()
    private var maxItem: Int = -1
    fun max_value(): Int {
        return maxItem
    }

    fun push_back(value: Int) {
        queue.offer(value)
        if (maxItem < value)
            maxItem = value
    }

    fun pop_front(): Int {
        if (queue.isEmpty()) {
            maxItem = -1
            return -1
        }
        var res = queue.poll()

        if (queue.isEmpty()){
            maxItem = -1
            return -1
        }
        if (res == maxItem) {
            maxItem = queue.peek()
            var size = queue.size
            while (size>0){
                this.push_back(queue.poll())
                size--
            }
        }
        return res
    }

}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */