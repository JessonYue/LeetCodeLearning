package com.github.leetcode.p0018_4sum;

import java.util.*;

/**
 * https://leetcode-cn.com/problems/4sum/
 * <p>
 * 四数之和：
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
 * 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 注意：
 * 答案中不可以包含重复的四元组。
 * <p>
 * 示例：
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * <p>
 * 满足要求的四元组集合为：
 * [
 * [-1,  0, 0, 1],
 * [-2, -1, 1, 2],
 * [-2,  0, 0, 2]
 * ]
 * <p>
 * 时间复杂度在 O()
 */
class Solution {
    /**
     * --------------------我的代码--------------------
     */
    /*
        执行用时 :419 ms, 在所有 Java 提交中击败了5.01%的用户
        内存消耗 :40 MB, 在所有 Java 提交中击败了10.53%的用户
     */
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> lists = new ArrayList<>();
        if (nums.length < 4) {
            return lists;
        }
        //map去重复:是指四元组中所有元素都不能同时相同
        HashMap<String, String> map = new HashMap<>();
        for (int i = 0; i < nums.length - 3; i++) {
            for (int j = i + 1; j < nums.length - 2; j++) {
                for (int k = j + 1; k < nums.length - 1; k++) {
                    for (int l = k + 1; l < nums.length; l++) {
                        int sum = nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target) {
                            //判断 nums[i]  nums[j]  nums[k]  nums[l]是否已经在lists中
                            int[] arr = {nums[i], nums[j], nums[k], nums[l]};
                            Arrays.sort(arr);
                            String key = Arrays.toString(arr);
                            if (!map.containsKey(key)) {
                                ArrayList<Integer> list = new ArrayList<>();
                                list.add(nums[i]);
                                list.add(nums[j]);
                                list.add(nums[k]);
                                list.add(nums[l]);
                                lists.add(list);
                                map.put(key, key);
                            }
                        }
                    }
                }
            }
        }
        return lists;
    }

    public static void main(String[] args) {
        int[] nums = {-5, 5, 4, -3, 0, 0, 4, -2};
        int target = 4;
        Solution solution = new Solution();

        List<List<Integer>> lists = solution.fourSum(nums, target);

        for (List<Integer> list : lists) {
            System.out.println(Arrays.toString(list.toArray()));
        }
    }

    /**
     * --------------------别人的代码--------------------
     */

}