package day18

import java.util.*

class MaxQueue() {
    var queue:Queue<Int> = LinkedList()
    var deque:Deque<Int> = LinkedList()

    fun max_value(): Int {
        if(deque.isEmpty())
            return -1;
        return deque.peek()
    }

    fun push_back(value: Int) {
        queue.add(value)
        while (!deque.isEmpty() && deque.last < value){
            deque.removeLast()
        }
        deque.add(value)
    }

    fun pop_front(): Int {
        if (queue.isEmpty())
            return-1;
        val res = queue.poll()
        if (!deque.isEmpty() && deque.peek()==res)
            deque.poll();
        return res
    }

}

fun main() {

}