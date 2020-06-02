class Solution {

    /**
     * 最佳买股票算法
     * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
       设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
       注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
     */
    //思路分析：  使用贪心思想 找出价格波动振幅中，所有正收益差值加起来
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        for(int i = 1;i < prices.length;i++){

            if(prices[i] > prices[i-1]){
               maxProfit += prices[i] - prices[i-1];
            }
        }

        return maxProfit;
    }
}