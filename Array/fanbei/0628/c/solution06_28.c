#include <stdlib.h>
#include <stdio.h>
/**
 * 1343. 大小为 K 且平均值大于等于阈值的子数组数目
 * 给你一个整数数组 arr 和两个整数 k 和 threshold 。
 * 请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
 */

int numOfSubarrays(int *arr,int arrSize,int k,int threshold){
    if(arrSize == 0|| k<0){
        return 0;
    }
    int sumTarget = k*threshold;
    int sum = 0;
    int result = 0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum>=sumTarget){
        result++;
    }
    for (int pos = k;pos<arrSize;pos++){
        sum+=arr[pos]-arr[pos-k];
        if(sum>=sumTarget){
            result++;
        }
    }
    return result;
}

