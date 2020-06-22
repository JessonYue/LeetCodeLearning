
class Solution {
    public int arrayNesting(int[] nums) {
        int max = 1;
        for(int i = 0; i < nums.length; i++){
            if(max > nums.length/2)
                return max;
            int curMax = 1;
            int cur = nums[nums[i]];
            while(nums[i] != cur){
                curMax++;
                cur = nums[cur];
            }
            max = curMax > max? curMax : max;
        }
        return max;
    }
}