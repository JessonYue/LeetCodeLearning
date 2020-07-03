package staudy

class Algorithm6_29 {
    fun numOfSubArrays(arr:Array<Int>,k:Int,threshold:Int) : Int{
        var sum = 0
        var result = 0
        var sumTarget = k * threshold
        for (i in 1..k){
            sum += arr[i]
        }

        var adder = sum - sumTarget
        if (adder >= 0){
            result++
        }

        var pos = k
        for (i in 1..arr.size - k){
            adder = adder+arr[pos]-arr[i]
            if (adder >= 0){
                result++
            }
            pos++
        }
        return result
    }
}