public class Solution {

    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i]<=target){
                for (int j = (nums.length-1); j >= 0; j--){
                    if(nums[j]<=target){
                        if(nums[i]+nums[j]==target){
                            return new int[]{i,j};
                        }
                    }
                }
            }

        }
        return null;
    }
}