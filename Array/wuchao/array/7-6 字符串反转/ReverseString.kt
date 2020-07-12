package com.slow.lib.practice.string

/**
 * @Author wuchao
 * @Date 2020/7/6-10:04 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class ReverseString {
    fun reverseString(s: CharArray): Unit {
        var start = 0
        var end = s.size -1
        while(start<end){
            val temp = s[start]
            s[start] = s[end]
            s[end] = temp
            start++
            end--
        }
    }
}