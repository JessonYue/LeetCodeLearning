//
// Created by 张俊伟 on 2020/6/28.
//


//暴力解法  时间超时
int numOfSubarrays1(int *arr, int arrSize, int k, int threshold) {
    int count = 0;
    int size = arrSize - k + 1;
    for (int i = 0; i < size; ++i) {
        int j = i + k;
        int sum = 0;
        for (int l = i; l < j; ++l) {
            sum += arr[l];
        }
        if (sum >= k * threshold)
            count++;
    }
    return count;
}

//参考  窗口滑动+动态规划
int numOfSubarrays(int *arr, int arrSize, int k, int threshold) {
//1、先求出前 k 数的和，与k*threshold 进行比较
    int sumk = 0;
    int count = 0;
    int i = 0;
    while (i < k) {
        sumk += arr[i++];
    }
    int t = sumk - k * threshold;
    if (t >= 0)
        count++;
    //
    sumk = arrSize - k;
    int pos = k;
    for (i = 0; i < sumk; ++i) {
        t = arr[pos] - arr[i] + t;
        if (t>=0)
            count++;
        pos++;
    }
    return count;
}