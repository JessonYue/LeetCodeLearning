package com.lanfairy.md.queue

fun findNumbers(nums: IntArray): Int {
   var tmp = nums.filter { it.toString().length % 2 == 0 }
    return tmp.size
}