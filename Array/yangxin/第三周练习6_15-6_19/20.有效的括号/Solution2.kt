package com.example.admin.myapplication.stack

import java.util.*

/**
 *create by yx
 *on 2020/6/16
 */
class Solution2 {
    private val map: Map<Char, Char> = mapOf('(' to ')', '[' to ']', '{' to '}')

    fun isValid(s: String): Boolean {
        if (s == null || s.isEmpty()) {
            return true;
        }
        val stack: Stack<Char> = Stack()

        for (char: Char in s) {
            when {
                stack.isEmpty() -> {
                    stack.push(char)
                }
                map[stack.peek()] == char -> {
                    stack.pop()
                }
                else -> {
                    stack.push(char)
                }
            }
        }

        return stack.isEmpty()
    }
}