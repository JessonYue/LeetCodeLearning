//
// Created by hasee on 2020/6/29.
//
//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
//
// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
// 示例 1:
//
// 输入: [3,3,5,0,0,3,1,4]
//输出: 6
//解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
//
// 示例 2:
//
// 输入: [1,2,3,4,5]
//输出: 4
//解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。  
//     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。  
//     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
//
//
// 示例 3:
//
// 输入: [7,6,4,3,1]
//输出: 0
//解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
// Related Topics 数组 动态规划
/**
 *  dp[第i天][卖出次数][当前是否持股]
 *  dp[i][0][0] = 0
 *
 *  //第i天卖出次数是0，持股1可能是前一天没操作，或者今天买了股票
 *  dp[i][0][1] = max(dp[i-1][0][1],dp[i-1][0][0]-prices[i])
 *
 *  可能今天卖出
 *  dp[i][1][0] = max(dp[i-1][1][0],dp[i-1][0][1]+prices[i])
 *
 * 卖出过一次，持股；可能今天买的，也可能之前买的
 *  dp[i][1][1] = max(dp[i-1][1][1],dp[i-1][1][0]-prices[i])
 *
 *  dp[i][2][0] = max(dp[i-1][2][0],dp[i-1][1][1]+prices[i])
 *
 *  dp[i][2][1] = min
 */
#include <vector>
#include <cstdio>

#define INT_MIN (1 << 31 >> 1)
using namespace std;

int maxProfit(vector<int>& prices) {
    int dp01 = INT_MIN;
    int dp10 = 0;
    int dp11 = INT_MIN;
    int dp20 = 0;
    for (int price : prices) {
        dp01 = max(dp01, - price);
        dp10 = max(dp10, dp01 + price);
        dp11 = max(dp11, dp10 - price);
        dp20 = max(dp20, dp11 + price);
    }
    return dp20;
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int max = maxProfit(prices);
    printf("max = %d\n", max);
    printf("INT_MIN = %d\n", INT_MIN);
    return 0;
}