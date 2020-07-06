package staudy

import java.util.*

class Algorithm6_17{

    val queue = LinkedList<Int>()
    val max = LinkedList<Int>()
    fun max_value() : Int{
        return if (max.size <= 0) -1 else max.first
    }

    fun push_block(value: Int){
        queue.add(value)
        while (max.size != 0 && max.first < value){
            max.removeLast()
        }
        max.add(value)
    }

    fun pop_front() : Int{
        if (max.size != 0 && queue.peek() == max.first){
            max.removeFirst()
        }
        return if (queue.size == 0) -1 else queue.poll()
    }
}

fun main(args: Array<String>) {
    val stack:Stack<Char> = Stack()
    stack.add('1')
    stack.add('2')
    stack.add('3')
    stack.add('4')
    stack.add('5')
    stack.add('6')

    stack.forEachIndexed { index, it ->
        if (index == 0) return@forEachIndexed
        else print(it)
    }


}