package com.example.kotlinproject

import java.lang.StringBuilder

fun main() {

    var solution = Solution()
    val result = solution.removeDuplicates("abbaca")
}

class Solution {

    fun removeDuplicates(S: String): String {
        var sb = StringBuilder()
        var currentPos = 0
        for (i in 0 until S.length) {
            if (currentPos != 0 && S.get(i) == sb.get(currentPos - 1)) {
                sb.deleteCharAt(currentPos - 1)
                currentPos--
            } else {
                sb.append(S.get(i))
                currentPos++
            }
        }
        return sb.toString();
    }
}