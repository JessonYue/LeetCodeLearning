package day45_0715

fun moveZeroes(nums: IntArray): Unit {

    if(nums == null)
        return
    var j:Int = 0
    //for (i in 0..nums.size-1){
    for (i in 0 until nums.size){
        if(nums[i] != 0){
            var temp:Int = nums[i]
            nums[i] = nums[j]
            nums[j++] = temp
        }
    }

}