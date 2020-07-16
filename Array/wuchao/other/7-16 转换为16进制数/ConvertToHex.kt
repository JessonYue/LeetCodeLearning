package com.slow.lib.practice.array

/**
 * @Author wuchao
 * @Date 2020/7/16-9:33 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class ConvertToHex {
    fun toHex(num: Int): String {
        val chars = charArrayOf('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f')
        val mask = 15
        var nums = num
        var result = ""
        for(i in 0..7){
            val bit = nums and mask
            nums = nums ushr 4
            if(nums==0){
                if(bit>0){
                    result = chars[bit].toString()+result
                }
            } else {
                result = chars[bit].toString()+result
            }
        }
        if(result.isEmpty()){
            result = "0"
        }
        return result
    }
}