package day23


fun findNumbers(nums: IntArray): Int {
    var sum = 0
    nums.forEach { i ->
        var count = 0
        var index = i;
        while (index != 0) {
            index = index/10;
            count++
        }
        if (count % 2 == 0)
            sum = sum + 1;
    }
    return sum;
}


fun main() {
    val intArr: IntArray = intArrayOf(12,345,2,6,7896)
    print(findNumbers(intArr));
}



