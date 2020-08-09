package com.slow.lib.practice.others

import java.util.*

/**
 * @Author wuchao
 * @Date 2020/8/7-9:40 AM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class ContainsDuplicate {
    fun containsDuplicate(nums: IntArray): Boolean {
        val hashSet = HashSet<Int>()
        for(item in nums){
            if(!hashSet.add(item)) return true
        }
        return false
    }
}