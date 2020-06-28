package L20

import java.util.*


fun isValid(s: String): Boolean {
    val stack = Stack<Char>()
    s.forEach {
        if ('{' == it || '[' == it || '(' == it) {
            stack.push(it)
        } else {
            if (stack.isEmpty()) {
                return false
            }
            val peek = stack.peek()
            if (peek == '{' && it == '}') {
                stack.pop();
            }
            if (peek == '[' && it == ']') {
                stack.pop();
            }
            if (peek == '(' && it == ')') {
                stack.pop();
            }
        }

    }
    return stack.isEmpty()

}


fun main() {

}