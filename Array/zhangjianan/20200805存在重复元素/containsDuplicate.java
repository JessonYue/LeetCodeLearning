class Solution {
    public boolean containsDuplicate(int[] nums) {
        int len=nums.length;
        int i;
        for( i=1;i<len;i++){
            int temp=nums[i];
            int j=i-1;
            for( ;j>0&&temp<nums[j];j-- ){
                nums[j+1]=nums[j];
            }
            nums[j+1]=temp;
        }
        for(i=0;i<len-1;i++){
            if(nums[i]==nums[i+1]) return  true;
        }
        return false;
    }
}