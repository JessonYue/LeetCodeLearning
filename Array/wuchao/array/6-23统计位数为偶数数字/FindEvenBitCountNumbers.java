package com.slow.lib.practice.array;

/**
 * @Author wuchao
 * @Date 2020/6/23-10:17 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class FindEvenBitCountNumbers {
    public int findNumbers(int[] nums) {
        int count = 0;
        for (int item:nums){
            if((getBitCounts(item)&1)==0){
                count++;
            }
        }
        return count;
    }

    public int getBitCounts(int num){
        int count = 1;
        while((num=num/10)>=1){
            count++;
        }
        return count;
    }
}
