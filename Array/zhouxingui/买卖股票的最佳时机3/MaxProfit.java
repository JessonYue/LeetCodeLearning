public class MaxProfit {
    public int maxProfit(int[] prices) {
        
        int minPrice1 = Integer.MAX_VALUE;         
        int maxProfit1 = 0;                        
        int maxProfitAfterBuy = Integer.MIN_VALUE; 
        int maxProfit2 = 0;                        
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

/** 
方法2： 模拟真实交易
在一定的天数内，我们最多可以进行两次交易，分为 买-卖-买-卖，所以问题的关键就是找到这4个点的最优分布
回到本方法，核心的思想就是：
第一次买入 / 第一次卖出 / 第二次买入 / 第二次卖出 这四个过程都可能发生在今天！
先看一个例子：

我手上有10元
第一次买入花了2元， 利润为 -2 元
第一次卖出，买了4元，利润为 4-2 = 2 元
第二次买入，花了3元，利润为 2-3 = -1 元
第二次卖出，卖了5元，利润为 -1 + 5 = 4 元

所以下面我们就定义了4个变量与上述4个过程对应：

第一次买入后的状态： minPrice1:minPrice1: 最低价格
第一次卖出后的状态： maxProfit1:maxProfit1: 第一次交易最大利润
第二次买入后的状态： maxProfitAtferBuy:maxProfitAtferBuy: 第二次买入后的最大剩余利润
第二次卖出后的状态： maxProfit2:maxProfit2: 当天能获得最大最大利润

然后遍历每一天，在每一天我们都作 4个假设，并更新上面4个状态；
1.假设今天第一次买入：更新 最低价格
2.假设今天第一次卖出：更新 第一次最大利润
3.假设今天第二次买入：更新 第二次买后的最大剩余利润
4.假设今天第二次卖出：更新 当天能获得的最大利润

其中，如果理解 maxProfitAfterBuymaxProfitAfterBuy ？ 即： 第二次买入后的最大剩余利润

比如：今天我第一次卖出股票利润为5元，明天价格为2元，后天价格为3元
你在哪天第二次买？你当然在明天啊，因为成本低，这样第二次买入后你手上的剩余利润就越大，这样往后你就只需要找哪天价格最高卖出去就行了，因为这个时候，你卖多少钱，你的总利润就相当于多了多少！
当然后面还有可能价格有1元的，所以这个 maxProfitAfterBuymaxProfitAfterBuy 也是不停的更新

结合代码和下面的表格，模拟一下，就很容易理解了！



作者：xfzhao
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/mai-gu-piao-de-zui-jia-shi-ji-iii-yi-kan-jiu-dong-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/