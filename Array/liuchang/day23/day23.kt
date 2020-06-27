package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/23
 * @describe
 */
class day23 {
    
    fun findNumbers(nums: IntArray, numSize: Int): Int {
        var count = 0;
        for (i in 0 until numSize) {
            var n = 1;
            var br = 10
            while (br < nums[i]) {
                br *= 10;
                n++
            }
            if (n % 2 == 0) {
                count++;
            }
        }
        return count;
    }

    fun main(args: Array<String>) {
        var data = intArrayOf(12, 345, 2, 6, 7896);

        System.out.println("=====" + findNumbers(data, 5));
    }
}