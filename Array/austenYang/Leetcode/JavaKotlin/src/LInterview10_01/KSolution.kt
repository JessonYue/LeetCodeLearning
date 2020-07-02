package LInterview10_01


fun merge(A:IntArray,m:Int,B:IntArray,n:Int){
     B.copyInto(A,m).sort()
}
fun main() {
    val intArrayOf = intArrayOf(1, 2, 3, 0, 0, 0)
    merge(intArrayOf,3, intArrayOf(2,5,6),3)
   intArrayOf.forEach(::print)
}