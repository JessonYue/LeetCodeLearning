/**
 * 2020.06.3
 * 28. 实现 strStr() //https://leetcode-cn.com/problems/implement-strstr/
 * 实现 strStr() 函数。
 * <p>
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 * <p>
 * 示例 1:
 * <p>
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 示例 2:
 * <p>
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 说明:
 * <p>
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * <p>
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 */
public class StrStr28 {
    public static void main(String[] args) {
        System.out.println(strStr("hello", "ll"));
        System.out.println(strStr("aaaaaa", "c"));
        System.out.println(strStr("aaacaa", "c"));
    }

    /**
     * 思路：在haystack中框柱needle长度的子串，然后逐步后移匹配
     */
    private static int strStr(String haystack, String needle) {
        if (haystack == null || needle == null) return 0;
        for (int i = 0; i < haystack.length() - needle.length() + 1; ++i) {
            if (haystack.substring(i, i + needle.length()).equals(needle)) {
                return i;
            }
        }
        return -1;
    }
}
