package com.example.lsn37_dagger2_subcomponent;

/**
 * 123. 买卖股票的最佳时机 III
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */
public class Solution06_29 {

    public int maxProfit(int[] prices) {

        if (prices.length < 2) {
            return 0;
        }

        int minPricel = Integer.MAX_VALUE;
        int maxProfit1 = 0;
        int maxProfitAfterBuy = Integer.MIN_VALUE;
        int maxProfit2 = 0;
        for (int price : prices) {
            minPricel = Math.min(minPricel, price);//第一次最小购买价格
            maxProfit1 = Math.max(maxProfit1, price - minPricel);//第一次卖出的最大利润
            maxProfitAfterBuy = Math.max(maxProfitAfterBuy, maxProfit1 - price);//第二次购买后剩余净利润
            maxProfit2 = Math.max(maxProfit2, price + maxProfitAfterBuy);//第二次卖出后,总共获得的最大利润(第三步的净利润+第4步卖出的股票价)
        }
        return maxProfit2;
    }

}
