class Solution {
    public int findNumbers(int[] nums) {
        int answer = 0;
        for(int i = 0; i<nums.length;i++){
            int num = nums[i];
            while((num/100)>0){
                num = num/100;
            }
            if((num /10)>0){
                answer += 1;
            }
        }
        return answer;
    }
}