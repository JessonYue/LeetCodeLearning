package L1;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Solution {
    /**
     * 1 .穷举法
     *
     * @param nums
     * @param target
     * @return
     */
    public static int[] twoSum1(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            int a = nums[i];
            for (int j = i + 1; j < nums.length; j++) {
                if (a + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        return null;
    }

    public static int[] twoSum2(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            int ret = target - nums[i];
            for (int j = i + 1; j < nums.length; j++) {
                if (ret == nums[j]) {
                    return new int[]{i, j};
                }
            }
        }
        return nums;
    }

    /**
     *
     * @param nums
     * @param target
     * @return
     */
    public static int[] twoSum3(int[] nums, int target) {
            Map<Integer, Integer> indexNumMap = new HashMap<>();

            for (int i = 0; i < nums.length; i++) {
                indexNumMap.put(nums[i],i);
            }
            for (int i = 0; i < nums.length; i++) {
                int complement = target - nums[i];
                if (indexNumMap.containsKey(complement) && indexNumMap.get(complement) != i){
                    return new int[]{i,indexNumMap.get(complement)};
                }
            }
            return null;
    }

    public static int[] twoSum4(int[] nums, int target) {
       Map<Integer,Integer> indexNumMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (indexNumMap.containsKey(complement) && indexNumMap.get(complement) != i){
                return new int[]{i,indexNumMap.get(complement)};
            }
            indexNumMap.put(nums[i],i);
        }
        return null;

    }

    public static void main(String[] args) {


    }
}
