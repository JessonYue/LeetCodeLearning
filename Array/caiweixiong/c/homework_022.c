//
// Created by Vashon on 2020/6/29.
//

#include <stdio.h>

#define MAX(x, y) (x > y ? x : y)

// 买卖股票的最佳时机 III，LeetCode第123题
void homework_022_123(void) {
    int maxProfit_(int *prices, int pricesSize);
    int arr[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int max = maxProfit_(arr, 8);
    printf("The max value is : %d\n", max);
}

// 方法一：暴力法
int maxProfit(int *prices, int pricesSize) {
    if (!prices || pricesSize < 2)
        return 0;
    // 1.只有一次购买：两轮循环，每次取出数组中的一个元素，与它后面的元素求差，得到其中的最大值
    // 2.只有两次购买：同样的，两轮循环，
    //   第一次购买：取数组前两元素，且每轮循环第二个元素都后退一位
    int left = 0, right = 1, singleBuyMax = 0;
    for (left = 0; left < pricesSize - 1; ++left) {
        for (right = left + 1; right < pricesSize; ++right) {
            int temp = prices[right] - prices[left];
            if (temp > singleBuyMax)
                singleBuyMax = temp;
        }
    }
    //   第二次购买：取第一轮循环卖出的元素索引的后一位为起点，后面每一位为终点
    int firstLeft, firstRight, secondLeft, secondRight, doubleBuyMax = 0;
    if (pricesSize >= 4) {  // 当元素足够才进行二次购买的循环
        for (firstLeft = 0; firstLeft < pricesSize - 3; ++firstLeft) {
            int max1 = 0;
            for (firstRight = firstLeft + 1; firstRight < pricesSize - 2; ++firstRight) {
                int max2 = 0;
                for (secondLeft = firstRight + 1; secondLeft < pricesSize - 1; ++secondLeft) {
                    for (secondRight = secondLeft + 1; secondRight < pricesSize; ++secondRight) {
                        // 求出第二次购买中最大的值
                        int temp2 = prices[secondRight] - prices[secondLeft];
                        if (temp2 > max2)
                            max2 = temp2;
                    }
                }
                // 求出第一次购买中最大的值
                int temp1 = prices[firstRight] - prices[firstLeft];
                if (temp1 > max1)
                    max1 = temp1;
                // 求出两次购买中最大的那次组合
                int temp = max1 + max2;
                if (temp > doubleBuyMax)
                    doubleBuyMax = temp;
            }
        }
    }
    return MAX(singleBuyMax, doubleBuyMax);
}

// 方法二：动态规划
int maxProfit_(int *prices, int pricesSize) {
    int dp_i_0 = 0, dp_i_1 = -0xFFFF;
    int dp_pre_0 = 0; // 代表 dp[i-2][0]
    for (int i = 0; i < pricesSize; ++i) {
        int temp = dp_i_0;
        dp_i_0 = MAX(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = MAX(dp_i_1, dp_pre_0 - prices[i]);
        dp_pre_0 = temp;
    }
    return dp_i_0;
}