package luge


/*167. 两数之和 II - 输入有序数组*/

/*给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。*/

private val nums = intArrayOf(1, 2, 5, 8, -88)
private val target = 7


fun main() {
    val index1 = getIndex1(nums, target)
    println("the index is : ${+index1[0]},${+index1[1]}")
    val index2 = getIndex2(nums, target)
    println("the index is : ${+index2[0]},${+index2[1]}")

    val index3 = getIndex3(nums, target)
    println("the index is : ${+index3[0]},${+index3[1]}")
    println(200 * 300 * 400 * 500)

}

// 时间复杂度： O(nˆ2)
fun getIndex1(nums: IntArray, target: Int): IntArray {

    var start = 0

    for (i in nums.indices) {
        start = i
        for (j in i + 1 until nums.size) {
            if (target - nums[start] == nums[j]) {
                return intArrayOf(start, j)
            }
        }
    }

    return intArrayOf(-1, -1)
}

// 2遍哈希表
fun getIndex2(nums: IntArray, target: Int): IntArray {

    var map: HashMap<Int, Int> = HashMap()

    nums.forEachIndexed { index, value ->
        map[value] = index
    }

    nums.forEachIndexed { index, value ->
        if (map.containsKey(target - value) && index != target - value) {
            return intArrayOf(index,map[target - value]!!)
        }
    }

    return intArrayOf(-1, -1)

}


// 1遍哈希表
fun getIndex3(nums: IntArray, target: Int): IntArray {

    var map: HashMap<Int, Int> = HashMap()

    nums.forEachIndexed { index, value ->

        var complement = target - value

        if (map.containsKey(complement)) {
            return intArrayOf(map[complement]!!, index)
        }
        map[value] = index
    }
    return intArrayOf(-1, -1)

}


/*2020.06.11

    70. 爬楼梯
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

    注意：给定 n 是一个正整数。

    示例 1：

    输入： 2
    输出： 2
    解释： 有两种方法可以爬到楼顶。
    1.  1 阶 + 1 阶
    2.  2 阶
    示例 2：

    输入： 3
    输出： 3
    解释： 有三种方法可以爬到楼顶。
    1.  1 阶 + 1 阶 + 1 阶
    2.  1 阶 + 2 阶
    3.  2 阶 + 1 阶*/

