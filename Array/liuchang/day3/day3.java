public class day3{

    /**
     * 2020.06.3
     * 28. 实现 strStr() //https://leetcode-cn.com/problems/implement-strstr/
     * 实现 strStr() 函数。
     *
     * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
     *
     * 示例 1:
     *
     * 输入: haystack = "hello", needle = "ll"
     * 输出: 2
     * 示例 2:
     *
     * 输入: haystack = "aaaaa", needle = "bba"
     * 输出: -1
     * 说明:
     *
     * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
     *
     * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
     */

    /**
     * 算法思路
     * 1、首先 需要获取到需要匹配的字符串长度 needleLength
     * 2、进行循环 根据循环确定判断的开始位置 i 而 i+needleLength 则是获取到截取的尾部
     * 3、使用 equal 方法 进行判断 如果有匹配的方法进行打印
     * 4、使用 被判断字符串长度 减去 当前的位置 如果 等于 匹配字符串长度 则 认为循环的最后一次匹配
     * 5、当无法匹配时 则打印 失败消息
     *
     * 另 附言：严谨性来说 字符串 首先应该加入判断 是否为空
     * 但是 在面试中 经常会出现要求不去判空 在这种情况下
     * 当匹配字符串 为 null 时 则 会报 NPE 错误
     * 当匹配字符串 为 "" 时 因为 length 为 0 则 被取出第0个 则为"" 匹配后 第0个位置为匹配 所以会打印 0
     */

    public static void main(String[] args) {
//        String haystack = "hello";
//        String needle = "ll";
        String haystack = "aaaaa";
        String needle = "bba";
//        String needle = null;
//        String needle = "";
        if (haystack == null || haystack.length()  <=0) {
            System.out.println("haystack is empty");
            return;
        }
        if (needle == null || needle.length() <= 0) {
            System.out.println("needle is empty");
            return;
        }
        int needleLength = needle.length();
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.substring(i, i + needleLength).equals(needle)) {
                System.out.println("begin index ===> " + i);
                break;
            } else if (haystack.length() - i == needleLength && !haystack.substring(i, i + needleLength).equals(needle)) {
                System.out.println("no match ===> " + -1);
                break;
            }
        }
    }
}