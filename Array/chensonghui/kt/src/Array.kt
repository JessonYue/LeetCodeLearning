fun main(args: Array<String>) {
    val nums = intArrayOf(2, 7, 11, 15)
    val target = 9
    println(twoSum(nums, target).toList())
}

/**
 * 两数之和
 */
fun twoSum(nums: IntArray, target: Int): IntArray {
    val map = HashMap<Int, Int>()
    for (i in nums.indices) {
        val dx = target - nums[i]
        if (map.contains(dx)) {
            return intArrayOf(nums[i], dx)
        }
        map[nums[i]] = i
    }
    return intArrayOf()
}

