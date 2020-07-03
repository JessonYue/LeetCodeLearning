package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/29
 * @describe
 */
class day29 {

    fun maxProfit(prices: IntArray, pricesSize: Int): Int {
        var dp1 = 0;
        var dp2 = -0xFFFF;
        var dp3 = 0;
        var dp4 = -0xFFFF;

        for (i in 0 until pricesSize) {
            dp3 = maxValue(dp3, dp4 + prices[i]);
            dp4 = maxValue(dp4, dp1 - prices[i]);
            dp1 = maxValue(dp1, dp2 + prices[i]);
            dp2 = maxValue(dp2, 0 - prices[i]);
        }

        return dp3;
    }

    fun maxValue(dp1: Int, dp2: Int): Int {
        if (dp1 > dp2) {
            return dp1;
        } else if (dp2 > dp1) {
            return dp2;
        } else {
            return dp1;
        }
    }

    fun main(args:Array<String>){
        var datas = intArrayOf(3, 3, 5, 0, 0, 3, 1, 4);
        System.out.println("====="+maxProfit(datas,8));
    }

}