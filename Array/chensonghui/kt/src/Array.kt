fun main(args: Array<String>) {
    val nums = intArrayOf(2, 7, 11, 15)
    val target = 9
    println(twoSum(nums, target).toList())
    //暴力爬楼梯
    //println(climbStairs1(45))
    //记忆法爬楼梯
    println(climbStairs2(45))
}

/**
 * 两数之和
 */
fun twoSum(nums: IntArray, target: Int): IntArray {
    //这里用map 不用set ,考虑到负数的问题
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


/**
 * 爬楼梯 暴力法
 */
fun climbStairs1(n: Int): Int {
    if (n == 1) {
        return 1
    } else if (n == 2) {
        return 2
    }

    return climbStairs1(n - 2) + climbStairs1(n - 1)
}

//用于记录 剩余多少步直接得出结果
val map = HashMap<Int, Int>()

/**
 * 爬楼梯 记忆法
 */
fun climbStairs2(n: Int): Int {
    if (n == 1 || n == 0) {
        return 1
    }
    map[n]?.apply {
        return this
    }
    val step1 = climbStairs2(n - 1)
    map[n - 1] = step1
    val step2 = climbStairs2(n - 2)
    map[n - 2] = step2
    return step1 + step2
}



