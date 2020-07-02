package com.test.ktapplication


fun main() {
    val s = intArrayOf(2, 2, 2, 2, 5, 5, 5, 8)
    var result = numOfSubarrays(s, 3, 4)
    print("result is ${result}")
}

fun numOfSubarrays(arr: IntArray, k: Int, threshold: Int): Int {
    var sum = 0
    var count = 0
    val length = arr.size
    for (i in 0 until k) {
        sum += arr[i]
    }
    if (sum >= k * threshold) {
        count++
    }
    if (length == k) {
        return count
    }
    for (j in 0 until length - k) {
        sum -= arr[j]
        sum += arr[j + k]
        if (sum >= k * threshold) {
            count++
        }
    }
    return count
}
