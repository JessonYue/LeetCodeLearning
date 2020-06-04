package L28


fun strStr(haystack: String, needle: String): Int {
    val n = needle.length
    for (i in 0 until haystack.length - n + 1) {
        if (haystack.substring(i, i + n) == needle) {
            return i
        }
    }
    return -1
}

fun main() {

}