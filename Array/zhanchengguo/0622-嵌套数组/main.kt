
fun main() {
    val s = arrayOf(5, 4, 0, 3, 1, 6, 2)
    val result = arrayNesting(s)
    print("result is ${result}")
}

fun arrayNesting(nums: Array<Int>): Int {
    val visited = BooleanArray(nums.size)
    var res = 0
    for (i in nums.indices) {
        if (!visited[i]) {
            var start = nums[i]
            var count = 0
            do {
                start = nums[start]
                count++
                visited[start] = true
            } while (start != nums[i])
            res = Math.max(res, count)
        }
    }
    return res;

}

