package com.example.lsn37_dagger2_subcomponent;

public class Solution06_23 {

    public int findNumbers(int[] nums){
        int count = nums.length;
        if(count == 0 ){
            return 0;
        }
        int result = 0;
        int tmp = 0,bit = 0;
        for (int i = 0;i<count;i++){
            tmp = nums[i];
            bit = 0;
            while (tmp != 0) {
                tmp = tmp/10;
                bit++;
            }
            if (bit % 2 == 0) {
                result++;
            }
        }
        return result;
    }

}
