package com.slow.lib.practice.others

/**
 * @Author wuchao
 * @Date 2020/8/5-10:51 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class InsertBits {
    fun insertBits(N: Int, M: Int, i: Int, j: Int): Int {
        val m = (((1 shl (j-i+1))-1) shl i).inv()
        return (N and m) or (M shl i)
    }
}