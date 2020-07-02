public int maxProfit(int[] prices) {
        /**
         //fst的两个变量的意义与121题相同，就是简单的动态规划更新

         fstMineprice : 到该天为止第一次买入股票的最小价格（即所有股票价格的最小值）
         fstMaxprofit: 到该天为止第一次卖出股票的最大收益（即只交易一次的最大收益）

         //sec的两个变量的意义要注意，特别是secMinprice，不单纯是股票原价格，而是在此基础上减去第一次收益

         secMinprice: 到该天为止第二次买入股票的最小价格（第二次买入股票的价格是原股票价格减去第一次买卖收益）
         secMaxprofit: 到该天为止第二次卖出股票可获得的最大收益

         分别对四个变量进行相应的更新, 最后secMaxprofit就是最大
         **/
        int fstMineprice = Integer.MAX_VALUE, fstMaxprofit = 0;
        int secMinprice = Integer.MAX_VALUE, secMaxprofit = 0;
        for(int p : prices) {
        //更新fstMineprice与fstMaxprofit，这里应该没有问题，与121题一样
        fstMineprice = Math.min(fstMineprice, p);
        fstMaxprofit = Math.max(fstMaxprofit, p-fstMineprice);

        //更新secMineprice与secMaxprofit
        secMinprice = Math.min(secMinprice, p-fstMaxprofit);//加入的p产生的最小价格就是p减去第一次买卖的最大收益，以此更新secMinprice
        secMaxprofit = Math.max(secMaxprofit, p-secMinprice);//p产生的最大收益就是p减去第二次买入的最小价格secMinprice，以此更新secMaxprofit
        }
        return secMaxprofit;

}