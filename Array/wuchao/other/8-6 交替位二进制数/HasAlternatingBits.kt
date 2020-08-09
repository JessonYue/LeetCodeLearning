package com.slow.lib.practice.others

/**
 * @Author wuchao
 * @Date 2020/8/6-9:10 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class HasAlternatingBits {
    fun hasAlternatingBits(n: Int): Boolean {
        var flag = (n and 1)>0
        var move = n shr 1
        while(move!=0){
            val temp = move and 1
            if((temp>0&&flag)||(temp==0&&!flag)) return false
            flag = temp>0
            move = move shr 1
        }
        return true
    }
}