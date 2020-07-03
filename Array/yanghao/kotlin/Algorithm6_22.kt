package staudy

import kotlin.math.max

class Algorithm6_22 {

    fun arrayNesting(nums:Array<Int>) : Int{
        var i = 0
        var res = 0
        while (i < nums.size){
            var b = nums[i]
            var c = 0
            do {
                b = nums[b]
                c++
            }while (b != nums[i])
            i++;
            res = max(res,c)
        }

        return res
    }
}