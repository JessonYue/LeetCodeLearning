package L565

fun arrayNesting(nums: IntArray): Int {
    var res = 0
    nums.forEachIndexed { index, _ ->

        var count = 0
        var changeIndex = index
        while (nums[changeIndex] != -1) {
            changeIndex = nums[changeIndex]
            nums[index] = -1
            count++
        }
        if (count > res) res = count
    }
    return res
}