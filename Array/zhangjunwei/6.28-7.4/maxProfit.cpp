//
// Created by 张俊伟 on 2020/6/30.
//
#include <limits.h>

//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/
int max(int i1, int i2) {
    return i1 > i2 ? i1 : i2;
}

//int maxProfit(int *prices, int pricesSize) {
//    int dp_i_0 = 0;
//    int dp_i_1 = INT_MIN;
//    int dp_pre_0 = 0;// 代表 dp[i-2][0]
//    for (int i = 0; i < pricesSize; ++i) {
//        int temp= dp_i_0;
//        dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);
//        dp_i_1 = max(dp_i_1, dp_pre_0-prices[i]);
//        dp_pre_0 = temp;
//    }
//    return dp_i_0;
//}
int maxProfit(int* prices, int pricesSize){
    int     dp_i_10     = 0;
    int     dp_i_11     = INT_MIN;
    int     dp_i_20     = 0;
    int     dp_i_21     = INT_MIN;

    for(int i = 0; i < pricesSize; i++)
    {
        dp_i_20 = max(dp_i_20, dp_i_21 + prices[i]);
        dp_i_21 = max(dp_i_21, dp_i_10 - prices[i]);
        dp_i_10 = max(dp_i_10, dp_i_11 + prices[i]);
        dp_i_11 = max(dp_i_11, 0 - prices[i]);
    }

    return dp_i_20;
}