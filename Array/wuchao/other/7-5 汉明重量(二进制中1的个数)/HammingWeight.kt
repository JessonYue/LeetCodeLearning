package com.slow.lib.practice.others

/**
 * @Author wuchao
 * @Date 2020/7/5-10:49 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class HammingWeight {
    fun hammingWeight(n:Int):Int {
        var count = 0
        var source = n
        while(source!=0){
            count+=source and 1
            source = source ushr 1
        }
        return count
    }
}