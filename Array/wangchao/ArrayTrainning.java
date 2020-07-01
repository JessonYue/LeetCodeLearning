package com.example.alg_lib.leetcode;

public class ArrayTrainning {

    /**
     * 子数组的平均值
     * 给你一个整数数组 arr 和两个整数 k 和 threshold 。
     * 请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
     */

    public int numOfSubarrays(int[] a, int k, int threshold){
        int fast = k;
        int slow = 0;
        int len = a.length;
        int sum = 0;
        int[] sub = new int[k];
        if (k > len)return -1;
        while(fast <= len){
            int tmp = slow;
            //构造子数组
            for (int i = 0; i < k; i++) {
                sub[i] = a[tmp];
                tmp++;
            }
            if (avarege(sub) >= threshold){
                sum++;
            }
            fast++;
            slow++;
        }
        System.out.println("sum->>>" + sum);
        return sum;
    }

    //计算平均值
    public int avarege(int[] b){
        int sum = 0;
        for (int item : b){
            sum += item;
        }
        return sum / b.length;
    }


}
