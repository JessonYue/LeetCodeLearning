package com.ad.ads.predownload;

/**
 *  给你一个整数数组 arr 和两个整数 k 和 threshold 。
 *  请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
 */
class Test {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int count = 0;
        int minSum = k*threshold;
        for(int startIndex = 0; startIndex<= arr.length - k; startIndex++){
            int sum =0;
            for(int i = 0; i<k; i++){
                sum+=arr[startIndex+i];
            }
            if(sum >= minSum){
                count++;
            }
        }
        return count;
    }
}
