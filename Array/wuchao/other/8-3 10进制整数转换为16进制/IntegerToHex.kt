package com.slow.lib.practice.others

/**
 * @Author wuchao
 * @Date 2020/8/4-9:01 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class IntegerToHex {
    fun toHex(num: Int): String {
        val chars = charArrayOf('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f')
        var nums = num
        var result = StringBuilder()
        for(i in 0..7){
            val index = nums and 15
            result.append(chars[index])
            nums = nums ushr 4
            if(nums==0) break
        }
        return result.reverse().toString()
    }
}