package L1047

import java.lang.StringBuilder
import java.util.*


/**
 * 去除重复元素 栈
 */
fun removeDuplicates(s: String): String {
    val stack = Stack<Char>()
    stack.push(s[0])
    for (index in 1 until s.length) {
        var peek: Char? = null
        if (!stack.isEmpty()) {
            peek = stack.peek()
        }
        if (peek != null && peek == s[index]) {
            stack.pop()
        } else {
            stack.push(s[index])
        }
    }
    return StringBuilder().apply {
        stack.forEach { append(it) }
    }.toString()


}

fun main() {
    print(removeDuplicates("abbcc"))
}