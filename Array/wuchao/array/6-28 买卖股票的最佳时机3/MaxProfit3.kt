package com.slow.lib.practice.array

/**
 * @Author wuchao
 * @Date 2020/6/28-4:33 PM
 * @see
 * @description
 * @email 329187218@qq.com
 */
class MaxProfit3 {
    fun maxProfit(prices: IntArray): Int {
        var firstBuyMinPrice = Int.MAX_VALUE
        var firstSaleMaxProfit = 0
        var secondBuyMaxLeftProfit = Int.MIN_VALUE
        var secondSaleMaxProfit = 0
        for(item in prices){
            firstBuyMinPrice = Math.min(firstBuyMinPrice,item)
            firstSaleMaxProfit = Math.max(firstSaleMaxProfit,item-firstBuyMinPrice)
            secondBuyMaxLeftProfit = Math.max(secondBuyMaxLeftProfit,firstSaleMaxProfit-item)
            secondSaleMaxProfit = Math.max(secondSaleMaxProfit,secondBuyMaxLeftProfit+item)
        }
        return secondSaleMaxProfit
    }
}