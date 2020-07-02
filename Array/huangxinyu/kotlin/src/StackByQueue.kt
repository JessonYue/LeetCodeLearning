import java.util.*

open class StackByQueue {
    private val que: Queue<Int> = LinkedList();
    fun push(x: Int) {
        que.add(x)
        for (i in 0 until que.size) {
            que.add(que.peek())
            que.remove()
        }
    }

    fun pop(): Int {
        val peek = que.peek()
        que.remove()
        return peek
    }

    fun empty(): Boolean {
        return que.isEmpty()
    }

    fun top(): Int {
        return que.peek()
    }
}