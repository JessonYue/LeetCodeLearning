package com.slow.lib.practice.array;

/**
 * 这一题思前想后都没有解出来，然后看题解，学习这种比较容易理解的方式
 * 定义四个状态，1. 第一次买入最低价格 2. 第一次卖出最高利润 3. 第二次买入的剩余利润（需要第一次卖出的利润减去当时的价格,可能为负）4. 第二次卖出的最高利润
 * 这四个状态是一个一个递进的，后面的状态需要根据前面的状态来推导，四个状态都可能发生在当前
 * 遍历数组分别更新这四个状态，算出来的第四个状态就是最大利润。
 * 第三个状态是能够解出来的关键，因为它计算了到了第一次卖出的利润，加上第二次卖出的价格就是总利润，第二次买入的价格要尽可能低，那么剩余利润就更大，第二次卖出只要比第二次买入的价格高，就是赚
 * @Author wuchao
 * @Date 2020/6/28-4:30 PM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class MaxProfit3 {
    public int maxProfit(int[] prices) {
        int firstBuyMinPrice = Integer.MAX_VALUE;
        int firstSaleMaxProfit = 0;
        int secondBuyMaxLeftProfit = Integer.MIN_VALUE;
        int secondSaleMaxProfit = 0;
        for(int price:prices){
            firstBuyMinPrice = Math.min(firstBuyMinPrice,price);
            firstSaleMaxProfit = Math.max(firstSaleMaxProfit,price-firstBuyMinPrice);
            secondBuyMaxLeftProfit = Math.max(secondBuyMaxLeftProfit,firstSaleMaxProfit-price);
            secondSaleMaxProfit = Math.max(secondSaleMaxProfit,price + secondBuyMaxLeftProfit);
        }
        return secondSaleMaxProfit;
    }
}
