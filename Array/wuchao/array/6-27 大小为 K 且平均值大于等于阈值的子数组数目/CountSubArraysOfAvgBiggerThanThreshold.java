package com.slow.lib.practice.array;

/**
 * 因为子数组是连续的，可以先计算出前缀k的和，
 * 然后这个k个大小的数组"窗口"，每次向后滑动一位，前面一个窗口和减去左边的元素加上窗口最后一个元素即是新窗口的和，
 * 对比窗口的平均值和阈值的大小，不用除法求平均值，可以对比窗口和和阈值*k的大小，节省性能
 * @Author wuchao
 * @Date 2020/6/27-9:44 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class CountSubArraysOfAvgBiggerThanThreshold {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int count = 0;
        int i=0;
        int sum = 0;
        int thresholdK = threshold*k;
        while(i<k){
            sum+=arr[i++];
        }
        if(sum>=thresholdK){
            count++;
        }
        int j = 1;
        while(i<arr.length){
            sum+=(arr[i++]-arr[j++-1]);
            if(sum>=thresholdK){
                count++;
            }
        }
        return count;
    }
}
