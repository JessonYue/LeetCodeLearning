package mykotlin

import org.jetbrains.annotations.TestOnly
import java.util.*

class MyQueue {
    private var enqueue: Stack<Int> = Stack()
    private var dequeue: Stack<Int> = Stack()


    fun push(x: Int) {
        enqueue.push(x)
    }

    fun pop(): Int {
        if (empty()) return -1
        while (!enqueue.isEmpty()) {
            dequeue.push(enqueue.pop())
        }
        var res = dequeue.pop()

        while (!dequeue.empty()) {
            enqueue.push(dequeue.pop())
        }
        return res
    }

    fun peek(): Int {
        if (empty()) return -1
        while (!enqueue.isEmpty()) {
            dequeue.push(enqueue.pop())
        }
        var res = dequeue.peek()

        while (!dequeue.empty()) {
            enqueue.push(dequeue.pop())
        }
        return res
    }

    fun empty(): Boolean {
        return enqueue.empty()
    }


}

fun main(){
    var obj = MyQueue()
    obj.push(1)
    obj.push(2)
    var param_3 = obj.peek()
    var param_2 = obj.pop()
    var param_4 = obj.empty()
    println(param_4)
}