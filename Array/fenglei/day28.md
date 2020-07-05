难度困难423收藏分享切换为英文关注反馈

给定一个数组，它的第 *i* 个元素是一支给定的股票在第 *i* 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 *两笔* 交易。

**注意:** 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1:**

```
输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
```

**示例 2:**

```
输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```

**示例 3:**

```
输入: [7,6,4,3,1] 
输出: 0 
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
```





### Java

```java
  private int maxProfit(LinkedList<Integer> prices) {
        if (prices.size() <= 1) return 0;
        int temp = prices.get(0);
        LinkedList<Integer> profit = new LinkedList<>();
        profit.addLast(0);
        // 从前往后计算在每个位置买入的最大利润
        for (int i = 1; i < prices.size() - 1; i++) {
            profit.addLast(Math.max(profit.get(i - 1), prices.get(i) - temp));
        }
        System.out.println(profit);
        temp = prices.getLast();
        int res = profit.getLast();
        for (int i = prices.size() - 2; i >= 0; --i) {
            // 从后往前计算第二次买入位置的利润，并筛选最大利润
            res = Math.max(res, temp - prices.get(i) + profit.get(i));
        }
        return res;
    }
```



