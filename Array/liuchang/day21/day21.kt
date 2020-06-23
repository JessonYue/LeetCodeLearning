package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/23
 * @describe
 */
class day21 {


    fun arrayNesting(nums: IntArray, numSize: Int): Int {
        var numData = 0;
        var data = IntArray(numSize);
        var dataCount = 0;
        for (i in 0 until numSize) {
            data[dataCount] = nums[numData];
            numData = nums[numData];
            if (data[0] == numData && dataCount > 1) {
                break;
            }
            dataCount++;

        }
        return dataCount;
    }

    fun main(args:Array<String>){
        var data = intArrayOf(5, 4, 0, 3, 1, 6, 2);
        System.out.println("====="+arrayNesting(data,7));
    }
}