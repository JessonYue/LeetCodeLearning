class Solution {
    public int findNumbers(int[] nums) {
        
        if(nums == null || nums.length == 0) return 0;
        int len = nums.length;
        int count = 0;
        for(int i = 0; i < len; i++) {
            int bitNum = 0;
            int iVal = nums[i];
            do {
                bitNum++;
                iVal = iVal / 10;
            } while(iVal > 0);

            if(bitNum % 2 == 0) count++;
        }
        return count;

        /** 另一种思路，把时间复杂度降低了，但是看到提交给出的运行速度，还没有上面的写法快
        int res=0;
        for(int i:nums){
            if(String.valueOf(i).length()%2==0){
                res++;
            }
        }

        return res;
        */
    }
}