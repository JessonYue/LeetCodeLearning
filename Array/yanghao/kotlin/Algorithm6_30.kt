package staudy

import kotlin.math.max

class Algorithm6_30 {
    fun maxProfit(prices : Array<Int>?) : Int{
        if (prices == null && prices?.size == 0){
            return 0
        }

        val len = prices?.size
        var min = prices?.get(0)
        var max = prices?.get(len!! - 1)
        var maxPro1 = 0
        var maxPro2 = 0
        val profit1 = arrayOfNulls<Int>(len!!)
        val profit2 = arrayOfNulls<Int>(len)
        for (i in 1..len){
            if (prices[i] <=  min!!){
                min = prices[i]
            }else{
                maxPro1 = max(maxPro1,prices[i]-min)
            }

            profit1[i] = maxPro1
            if (prices[len - 1 - i] >= max!!){
                max = prices[len-1-i]
            }else{
                maxPro2 = max(maxPro2,max-prices[len-1-i])
            }
            profit2[len-i-1]=maxPro2
        }

        var res = Int.MAX_VALUE
        for (i in 1..len){
            res = max(res,profit1[i]!! + profit2[i]!!)
        }

        return res
    }
}