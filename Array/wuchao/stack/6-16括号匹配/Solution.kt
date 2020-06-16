import java.util.*

/**
 * @Author wuchao
 * @Date 2020/6/16-9:00 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class Solution {
    fun isValid(s: String): Boolean {
        val stringLength = s.length
        if (stringLength % 2 != 0) return false
        val stack = Stack<Char>()
        for (i in 0..stringLength-1) {
            val item = s[i]
            if (isLeft(item)) {
                stack.push(item)
            } else {
                if (stack.isEmpty()) return false
                if (isMatched(stack.peek(), item)) {
                    stack.pop()
                } else {
                    return false
                }
            }
        }
        if (stack.isEmpty()) return true
        return false
    }

    private fun isMatched(a: Char, b: Char): Boolean {
        if (a == '{') return b == '}'
        if (a == '[') return b == ']'
        if (a == '(') return b == ')'
        return false
    }

    private fun isLeft(a: Char): Boolean {
        return a == '{' || a == '[' || a == '('
    }
}