package staudy
class Algorithm6_23 {

  fun findNumbers(nums:Array<Int>) : Int{
      var a = 0
      for (i in 1..nums.size){
        val c = nums[i].toString()
        if (c.length %2  == 0){
          a++
        }
      }
    return a
  }
}