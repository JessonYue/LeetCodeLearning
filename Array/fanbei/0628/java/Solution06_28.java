package com.example.lsn37_dagger2_subcomponent;

/**
 * 1343. 大小为 K 且平均值大于等于阈值的子数组数目
 * 给你一个整数数组 arr 和两个整数 k 和 threshold 。
 * 请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
 */
public class Solution06_28 {

    public int numOfSubarrays(int[] arr, int k, int threshold) {

        if (arr.length == 0) {
            return 0;
        }
        int sunTarget = k * threshold;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int adder = sum - sunTarget;
        if (adder >= 0) {
            result++;
        }
        for (int i = 0, pos = k, count = arr.length - k; i < count; i++, pos++) {
            adder += arr[pos] - arr[i];
            if (adder >= 0) {
                result++;
            }
        }
        return result;
    }

}
