```c
给你一个整数数组 arr 和两个整数 k 和 threshold 。
请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。

示例 1：
输入：arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
输出：3
解释：子数组 [2,5,5],[5,5,5] 和 [5,5,8] 的平均值分别为 4，5 和 6 。其他长度为 3 的子数组的平均值都小于 4 （threshold 的值)。

示例 2：
输入：arr = [1,1,1,1,1], k = 1, threshold = 0
输出：5

示例 3：
输入：arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
输出：6
解释：前 6 个长度为 3 的子数组平均值都大于 5 。注意平均值不是整数。

示例 4：
输入：arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
输出：1

示例 5：
输入：arr = [4,4,4,4], k = 4, threshold = 1
输出：1

提示：
1 <= arr.length <= 10^5
1 <= arr[i] <= 10^4
1 <= k <= arr.length
0 <= threshold <= 10^4

```



### C

```c
// 第一次超时解法(结果正确，但是时间超时)
int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    int sum = 0;
    int count = 0;
    unsigned int i;
    unsigned int j;
    for (i = 0; i <= arrSize - k; ++i) {
        // 获取子数组
        for (j = 0; j < k; ++j) {
           sum += arr[j];
        }
        if (sum >= k * threshold ){
            count++;
        }
        sum = 0;
        arr++;
    }
    return count;
}


// 看 LeetCode 优化代码
int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    if (arr == NULL || arrSize <= 0 || k <= 0 || k > arrSize) {
        return 0;
    }
    int thresholdCount = k * threshold;
    int sum = 0;
    int count = 0;
    unsigned int i;
    // 求出第一个子数组的和
    for (i = 0; i <  k; i++) {
        sum += arr[i];
    }
    if (sum >= thresholdCount){
        count++;
    }
    // 筛选后续子数组是否符号条件
    for (i = k; i < arrSize; i++) {
        sum += (arr[i] - arr[i - k]);
        if (sum >= thresholdCount){
            count++;
        }
    }
    return count;
}
```

