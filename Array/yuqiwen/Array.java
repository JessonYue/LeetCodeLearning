package leetCode;

import java.util.HashMap;

public class Array {
    public int[] twoSum(int[] nums, int target) {
        //核心原理： a+b=c， so a=c-b ，b=c-a. 差值必然要么存在map内，或者在后面。但是当后面的目标值放入时就又和前面命中了。
        //核心考察：对hashMap 时间复杂度为O(1)
        //一次for循环后 变为O(n)
        HashMap<Integer, Integer> map = new HashMap();
        for (int i = 0; i < nums.length; i++) {
            int difference = target - nums[i];
            if (map.containsKey(difference)) {
                return new int[]{i, map.get(difference)};
            }
            map.put(nums[i], i);
        }
        return null;
    }

}
