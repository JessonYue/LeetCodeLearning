package com.slow.lib.practice.array

/**
 * @Author wuchao
 * @Date 2020/7/15-10:28 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class FindUniqChar {
    fun firstUniqChar(s: String): Int {
        val count = IntArray(26)
        for(index in s.indices){
            count[s[index] - 'a']++
        }
        for(index in s.indices){
            if(count[s[index] - 'a'] == 1){
                return index
            }
        }
        return -1
    }
}