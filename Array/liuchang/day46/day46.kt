package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/7/16
 * @describe
 */
class day46 {

    private fun moveZeroes(nums:IntArray){
        var lastNumber = 0;
        for(i in nums.indices){
            if (nums[i] != 0) {
                nums[lastNumber] = nums[i];
                if (i != lastNumber) {
                    nums[i] = 0;
                }
                lastNumber++;
            }


        }
        for (element in nums){
            println("=====$element");
        }
    }

    fun main(args:Array<String>){
        moveZeroes(intArrayOf(1,0,3,0,10));
    }
}