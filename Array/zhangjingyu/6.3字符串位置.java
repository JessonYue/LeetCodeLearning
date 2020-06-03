public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        String haystack = "aabaa", needle = "ba";
        System.out.println(strStr(haystack,needle));
    }


    /**
     * 2020.06.3
     * 28. 实现 strStr() //https://leetcode-cn.com/problems/implement-strstr/
     * 实现 strStr() 函数。
     *
     * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
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
     * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
     *
     * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
     * @return
     */

    public int strStr(String haystack,String needle){
        if(needle == null || needle.length() == 0) {
            return 0;
        }
        int start  ;
//        while (haystack.charAt(i)!=haystack.charAt(j)){
//            i++;
//
//        }
        for(start = 0 ; start < haystack.length(); start++) {
            if(haystack.charAt(start)==needle.charAt(0)) {
                if(haystack.substring(start,start+needle.length()).equals(needle)) {
                    return start;
                }
            }
        }
        return -1;
    }



}