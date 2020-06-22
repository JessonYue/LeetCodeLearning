package com.example.computerdemo;

public class Solution06_22 {

    public int arrayNesting(int[] nums) {

        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            int j = i;
            int count = 0;
            while (nums[j] != -1) {
                count++;
                int temp = nums[j];
                nums[j] = -1;//标记被搜索过
                j = temp;
            }
            result = Math.max(result, count);
        }
        return result;
    }

}
