package L3


/**
 * 窗口滑动
 */
fun lengthOfLongestSubstring(s: String): Int {
    val hashset = hashSetOf<Char>()
    var rk = -1
    var ans = 0
    val n = s.length
    s.forEachIndexed { index, c ->
        if (index != 0) {
            // 当窗口左边界移动时，那么就要依次地把窗口最左边的元素移除
            hashset.remove(s[index - 1])
        }
        while (rk + 1 < n && !hashset.contains(c)) {
            hashset.add(c)
            rk++
        }
        ans = ans.coerceAtLeast(rk - index + 1)
    }
    return ans
}

fun main() {

}