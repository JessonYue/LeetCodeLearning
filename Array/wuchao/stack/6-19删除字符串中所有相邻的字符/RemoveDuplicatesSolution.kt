package com.slow.lib.practice.stack

import java.util.*

/**
 * @Author wuchao
 * @Date 2020/6/19-9:48 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class RemoveDuplicatesSolution {
    fun removeDuplicates(S: String): String {
        val stack = Stack<Char>()
        for(i in 0..S.length-1){
            if(stack.isEmpty()){
                stack.push(S[i])
            } else {
                if(stack.peek()==S[i]){
                    stack.pop()
                } else {
                    stack.push(S[i])
                }
            }
        }
        val stringBuilder = StringBuilder()
        for(item in stack){
            stringBuilder.append(item)
        }
        return stringBuilder.toString()
    }
}