package com.hlg.daydaytobusiness

import java.util.*

fun main() {
    val result = isValid("()[]{}[")
}

fun isValid(s: String): Boolean{
    val stack = Stack<Char>()
    for (i in 0 until s.length) {
        val c = s[i]
        if ('(' == c || '[' == c || '{' == c) {
            stack.push(c)
        } else {
            if (stack.isEmpty()) {
                return false
            }
            val top = stack.peek()
            stack.pop()
            if ('(' == top && c != ')' ||
                    '[' == top && c != ']' ||
                    '{' == top && c != '}') {
                return false
            }
        }
    }
    return stack.isEmpty()
}