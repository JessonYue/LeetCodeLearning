package com.github.leetcode.p0238_product_of_array_except_self;

import java.util.Arrays;

/**
 * https://leetcode-cn.com/problems/product-of-array-except-self/
 * <p>
 * 除自身以外数组的乘积：
 * 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
 *
 * <p>
 * 示例：
 * 输入: [1,2,3,4]
 * 输出: [24,12,8,6]
 * 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
 * <p>
 * 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * <p>
 * 进阶：
 * 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 * <p>
 * 时间复杂度在 O()
 */
class Solution {
    /**
     * --------------------我的代码--------------------
     */
    //要求：不要使用除法，且在 O(n)，这种解法的时间复杂度在O(n^2)
    /*public int[] productExceptSelf(int[] nums) {
        int[] result = new int[nums.length];
        int temp;
        for (int i = 0; i < nums.length; i++) {
            temp = 1;
            for (int j = 0; j < nums.length; j++) {
                if (i != j) {
                    temp *= nums[j];
                }
            }
            result[i] = temp;
        }
        return result;
    }*/
    //要求：不要使用除法，且在 O(n)
    public int[] productExceptSelf(int[] nums) {
        int N = nums.length;
        int[] result = new int[N];
        for (int i = 0; i < N; i++) {
            result[i] = 1;
        }
        int head = 1;
        int tail = 1;
        for (int i = 0; i < N; i++) {
            result[i] *= head;
            result[N - i - 1] *= tail;

            head *= nums[i];
            tail *= nums[N - i - 1];
        }
        return result;
    }

    public static void main(String[] args) {
//        int[] nums = {1, 2, 3, 4};//[24,12,8,6]
        int[] nums = {1, 2, 3, 4, 0};//[0,0,0,0,24]
        Solution solution = new Solution();
        System.out.println(Arrays.toString(solution.productExceptSelf(nums)));
    }

    /**
     * --------------------别人的代码--------------------
     */

    /**
     * 1, 2, 3, 4,5,6
     *6 10 12
     *
     * 720
     */
}