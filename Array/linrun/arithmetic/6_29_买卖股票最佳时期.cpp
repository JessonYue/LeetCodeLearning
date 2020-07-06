//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
//设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
//注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
int maxProfit(int* prices, int pricesSize){
    int lowerIndex = 0;
        int higherIndex = 0;
        int firstDelta = 0;
        int secondDelta = 0;
        int startIndex = 1;
        while (startIndex < pricesSize) {
            int delta = 0;
            bool hasFound = false;
            for (int i = startIndex; i < pricesSize; i++) {
                if (prices[i] - prices[lowerIndex] > delta) {
                    hasFound = true;
                    higherIndex = i;
                    delta = prices[higherIndex] - prices[lowerIndex];
                } else if (prices[i] - prices[lowerIndex] < delta) {
                    break;
                }
            }
            for (int i = startIndex; i < higherIndex; i++) {
                if (prices[i] < prices[lowerIndex]) {
                    lowerIndex = i;
                }
            }
            if (delta > firstDelta || delta > secondDelta) {
                if (firstDelta > secondDelta) {
                    secondDelta = delta;
                } else {
                    firstDelta = delta;
                }
            }
            if (hasFound) {
                lowerIndex = higherIndex + 1;
            } else {
                lowerIndex++;
            }
            startIndex = lowerIndex + 1;
        }
        return firstDelta + secondDelta;
}