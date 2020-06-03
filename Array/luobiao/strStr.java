/**
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


结题思路：先取到needle字符串的首字母位置及长度，遍历haystack字符串的每一字母，如果找到匹配needle的首字母，在haystack字符串截取needle长度的字符串，判断是否相等。如果相等，返回
否则，继续遍历

**/


class Solution {
    public int strStr(String haystack, String needle) {
        if(needle == null || "".equals(needle)) {
            return 0;
        } else if (haystack == null || "".equals(haystack)){
            return -1;
        } else {
            //分组预处理
            char findFirst = needle.charAt(0);
            int length = needle.length();
            int i=0;
            while (i<haystack.length()) {
                char charAt = haystack.charAt(i);
                if (charAt == findFirst) {
                    if ((i + length) <= haystack.length()) {
                        StringBuilder haysNeed = new StringBuilder();
                        for (int j=i; j<(i + length); j++) {
                            haysNeed.append(haystack.charAt(j));
                        }

                        if (needle.equals(haysNeed.toString())) {
                            return i;
                        }

                        i++;
                    } else {
                        return -1;
                    }

                } else {
                    i++;
                }
            }
        }

        return -1;
    }
}