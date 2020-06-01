package com.github.leetcode.p0167_two_sum_ii_input_array_is_sorted;

import java.util.Arrays;
import java.util.HashMap;

/**
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * <p>
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 说明:
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * <p>
 * 示例：
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * <p>
 * 时间复杂度在 O()
 */
class Solution {
    /**
     * --------------------我的代码--------------------
     */
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < numbers.length; i++) {
            if (map.containsKey(target - numbers[i])) {
                return new int[]{map.get(target - numbers[i]) + 1, i + 1};
            }
            if (!map.containsKey(numbers[i])) {
                map.put(numbers[i], i);
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] numbers = {2, 7, 11, 15};
        int target = 9;
        int[] twoSum = solution.twoSum(numbers, target);

        if (twoSum != null) {
            System.out.println(Arrays.toString(twoSum));
        }


    }

    /**
     * --------------------别人的代码--------------------
     */

}