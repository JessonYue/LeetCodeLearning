package xt

import java.util.*

class MeSolution {
    fun isValid(s: String): Boolean {
        if (s.length % 2 == 1) {
            return false
        }
        val stack: Stack<Char> = Stack<Char>()
        for (i in 0 until s.length) {
            val c = s[i]
            if (c == '{' || c == '[' || c == '(') {
                stack.push(c)
            } else {
                if (stack.empty()) {
                    return false
                }
                val preChar = stack.peek()
                if (preChar == '{' && c == '}' ||
                        preChar == '[' && c == ']' ||
                        preChar == '(' && c == ')') {
                    stack.pop()
                } else {
                    return false
                }
            }
        }
        return stack.empty()
    }
}