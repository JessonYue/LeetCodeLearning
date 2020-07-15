/**
     * 283. 移动零
     * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
     */
    fun moveZeroes(nums: IntArray): Unit {
        var tmp:Int
        var tail:Int = 0
        for (i in nums.indices) {
            if (nums[i] != 0) {
                tmp = nums[i]
                nums[i] = nums[tail]
                nums[tail++] = tmp
            }
        }
    }