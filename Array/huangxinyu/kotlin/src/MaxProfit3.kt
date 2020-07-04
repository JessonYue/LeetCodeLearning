class MaxProfit3 {
    fun maxProfit(prices: IntArray): Int {
        var hold1 = Int.MIN_VALUE
        var hold2 = Int.MIN_VALUE
        var release1 = 0
        var release2 = 0
        for (i in prices) {
            release2 = release2.coerceAtLeast(hold2 + i)
            hold2 = hold2.coerceAtLeast(release1 - i)
            release1 = release1.coerceAtLeast(hold1 + i)
            hold1 = hold1.coerceAtLeast(-i)
        }
        return release2
    }

    fun test() {
        val prices: IntArray = intArrayOf(3,3,5,0,0,3,1,4)
        print("maxProfit = ${maxProfit(prices)}")
    }
}
