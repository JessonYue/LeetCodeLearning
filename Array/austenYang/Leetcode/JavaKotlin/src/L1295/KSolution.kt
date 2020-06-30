package L1295

fun findNumbers1(nums: IntArray): Int {
    var count = 0
    nums.forEachIndexed { _, value ->
        if (value.toString().length % 2 == 0) {
            count++
        }
    }
    return count
}


fun findNumbers2(nums: IntArray): Int {
    var count = 0
    fun getIntCount(num: Int): Int {
        var intCount = 1
        var temp = num
        while ((temp / 10) != 0) {
            intCount++
            temp /= 10
        }
        return intCount
    }
    nums.forEachIndexed { _, value ->
        if (getIntCount(value) % 2 == 0) {
            count++
        }
    }
    return count
}


fun main() {
    println(findNumbers1(intArrayOf(1, 10, 3, 4, 5)))
    println(findNumbers2(intArrayOf(1, 10, 1111, 14, 5)))
}