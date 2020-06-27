class Solution {
    public int arrayNesting(int[] nums) {
        if(nums == null || nums.length == 0) return 0;

        int max = 0;
        for(int i = 0; i < nums.length; i++) {
            int count = 0;
            int temp = 0;
            int index = i;
            while(nums[index] >= 0) {
                count++;
                temp = index;
                index = nums[index];
                nums[temp] = -1;
            }
            if(count > max) max = count;
        }
        return max;
    }
}