package kotlin

import java.util.*

class SolutionKotlin {
    fun removeDuplicates(S: String): String {
        val s = S.toCharArray()
        val len = s.size
        val stack  = Stack<Char>()
        for (i in 0 until len) {
            if (stack.isEmpty() || s[i] != stack.peek()) {
                stack.push(s[i])
            } else {
                stack.pop()
            }
        }
        val str = StringBuilder()
        for (c in stack) {
            str.append(c)
        }
        return str.toString()

    }
}