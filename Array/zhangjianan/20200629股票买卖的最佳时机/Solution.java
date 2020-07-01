class Solution {
    public int maxProfit(int[] prices) {
      int minPrice1 = Integer.MAX_VALUE;  //第一次最小购买价格       
        int maxProfit1 = 0; // 2.第一次卖出的最大利润                       
        int maxProfitAfterBuy = Integer.MIN_VALUE;  // 3.第二次购买后的剩余净利润
        int maxProfit2 = 0;          // 4.第二次卖出后，总共获得的最大利润（第3步的净利润 + 第4步卖出的股票钱）               
        for(int price : prices) {
            // 1.第一次最小购买价格
            minPrice1  = Math.min(minPrice1,  price);

            // 2.第一次卖出的最大利润
            maxProfit1 = Math.max(maxProfit1, price - minPrice1);

            // 3.第二次购买后的剩余净利润
            maxProfitAfterBuy  = Math.max(maxProfitAfterBuy,  maxProfit1 - price );

            // 4.第二次卖出后，总共获得的最大利润（第3步的净利润 + 第4步卖出的股票钱）
            maxProfit2 = Math.max(maxProfit2, price + maxProfitAfterBuy);
        }
        return maxProfit2;
    }
    
}