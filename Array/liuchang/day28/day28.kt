package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/28
 * @describe
 */
class day28 {

    fun numOfSubarrays(arr: IntArray, arrSize: Int, k: Int, threshold: Int): Int {
        var count = 0;
        for (i in 0 until (arrSize - k + 1)) {
            var num = 0;
            for (j in i until (i + k)) {
                num += arr[j];
            }
            if (num / k >= threshold) {
                count++;
            }
        }
        return count;
    }

    fun main(args: Array<String>) {
        var datas = intArrayOf(2, 2, 2, 2, 5, 5, 5, 8);
        System.out.println("=====" + numOfSubarrays(datas, 8, 3, 4));
    }
}