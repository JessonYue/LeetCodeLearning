package com.example.admin.myapplication.stack

import java.util.*

/**
 *create by yx
 *on 2020/6/19
 * 1047. 删除字符串中的所有相邻重复项
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 */
class SolutionKotlinDeleteRepetition {

    fun removeDuplicates(S: String): String {
        if (S.isEmpty()) {
            return S;
        }

        val queue: Queue<Char> = LinkedList()
        for (char: Char in S) {
            queue.add(char)
        }

        var isContinue = true
        while (isContinue) {
            isContinue = false
            val size = queue.size
            var i = 0
            while (i < size) {
                val char = queue.poll()
                i++
                if (i == size) {
                    queue.add(char)
                    break
                }
                if (char == queue.peek()) {
                    isContinue = true
                    queue.poll()
                    i++
                } else {
                    queue.add(char)
                }
            }
        }

        val result: StringBuilder = StringBuilder()

        while (queue.isNotEmpty()) {
            result.append(queue.poll())
        }
        return result.toString()
    }
}