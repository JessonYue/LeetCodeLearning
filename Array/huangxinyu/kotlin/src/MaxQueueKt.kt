import java.util.*

class MaxQueueKt {
    private val queue: Deque<Int> = ArrayDeque()
    private val help: Deque<Int> = ArrayDeque()


    fun max_value(): Int {
        return if (queue.isEmpty()) -1 else help.peek()
    }

    fun push_back(value: Int) {
        queue.offer(value)
        while (!help.isEmpty() && value > help.peekLast()) {
            help.pollLast()
        }
        help.offer(value)
    }

    fun pop_front(): Int {
        if (queue.isEmpty()) {
            return -1
        }
        val `val` = queue.pop()
        if (help.peek() == `val`) {
            help.pop()
        }
        return `val`
    }
}