package com.test.ktapplication

fun main() {
    val s = arrayOf(12, 345, 2, 6, 7896)
    val result = findNumbers(s)
    print("result is ${result}")
}

fun findNumbers(nums:Array<Int>):Int{
    var count = 0
    for (num in nums) {
        if (num.toString().length % 2 == 0) {
            count++
        }
    }
    return count
}