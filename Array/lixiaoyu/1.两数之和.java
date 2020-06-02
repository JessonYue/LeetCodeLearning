import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            for (int j = i - 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    result[0] = nums[i];
                    result[1] = nums[j];
                }
            }
        }
        return result;
    }

    public static int[] twoSum1(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>(nums.length);
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int resu = target - nums[i];
            boolean containsKey = map.containsKey(resu);
            if (!containsKey) {
                map.put(nums[i], i);
            } else {
                result[0] = map.get(resu);
                result[1] = i;
                break;
            }
        }
        return result;
    }
}
// @lc code=end