package L1343


/**
 * 滑动窗口
 */
fun numOfSubarrays(arr: IntArray, k: Int, threshold: Int): Int {
    var sum = 0
    var result = 0
    for (i in 0 until k) {
        sum += arr[i]
    }
    var window = sum - k * threshold
    if (window >= 0) {
        result++
    }
    var pos = k
    for (i in 0 until arr.size - k) {
        window = window + arr[pos] - arr[i]

        if (window >= 0) {
            result++
        }
        pos++
    }
    return result
}

fun main() {
    println(numOfSubarrays(intArrayOf(2, 2, 2, 2, 5, 5, 5, 8), 3, 4))
}