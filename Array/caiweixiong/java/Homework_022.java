public class Homework_022 {

    // 买卖股票的最佳时机 III，LeetCode第123题
    void homework_022_123() {
        int arr[] = {3, 3, 5, 0, 0, 3, 1, 4};
        int max = maxProfit(arr);
        System.out.println(String.format("The max value is : %d", max));
    }

    private int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2)
            return 0;
        int singleBuyMax = 0, pricesSize = prices.length;
        for (int left = 0; left < pricesSize - 1; left++) {
            for (int right = left + 1; right < pricesSize; right++) {
                int temp = prices[right] - prices[left];
                if (temp > singleBuyMax)
                    singleBuyMax = temp;
            }
        }
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
        return Math.max(singleBuyMax, doubleBuyMax);
    }

    private int maxProfit_(int[] prices) {
        int pricesSize = prices.length;
        int dp_i_0 = 0, dp_i_1 = Integer.MIN_VALUE;
        int dp_pre_0 = 0; // 代表 dp[i-2][0]
        for (int i = 0; i < pricesSize; ++i) {
            int temp = dp_i_0;
            dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = Math.max(dp_i_1, dp_pre_0 - prices[i]);
            dp_pre_0 = temp;
        }
        return dp_i_0;
    }
}
