package L5;

/**
 * 学到 怎么枚举 字符串 子联系串
 * 回文字符串就是 左边起是一样的 右边起也是一样的
 */
public class Solution {

    public static String longestPalindrome1(String s) {
        char[] charArray = s.toCharArray();
        int n = charArray.length;
        if (n < 2) {
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        // 这里 循环第一层表示将要枚举的 子串的起始位置
        // n - 1 是
        /**
         * 在枚举的时候
         * 只需枚举长度大于等于 2 并且 超过了 当前得到的 最长回文子串 长度的那些子串
         * 长度大于等于2 那么 --> 左边界只需枚举到 倒数第二个位置，右边界从左边界 + 1 的位置开始枚举
         */
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (j - i + 1 > maxLen && validPalindromic(charArray, i, j)) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substring(begin, begin + maxLen);
    }

    /**
     * 中心扩散法
     * 判断回文字符串
     *
     * @param s
     * @return
     */
    public static String longestPalindrome2(String s) {
        int length = s.length();
        if (length < 2) {
            return s;
        }
        char[] charArray = s.toCharArray();

        int maxLen = 1;
        int begin = 0;
        for (int i = 0; i < length - 1; i++) {
            int oodLen = appendAroundCenter(charArray, i, i);
            int evenLen = appendAroundCenter(charArray, i, i + 1);


            int curMaxLen = Math.max(oodLen, evenLen);
            if (curMaxLen > maxLen) {
                maxLen = curMaxLen;

                begin = i - (maxLen - 1) / 2;
            }


        }
        return s.substring(begin,begin + maxLen);
    }

    /**
     * @return
     */
    private static int appendAroundCenter(char[] charArray, int left, int right) {
        int n = charArray.length;
        while (left >= 0 && right < n) {
            if (charArray[left] == charArray[right]) {
                left--;
                right++;
            } else {
                break;
            }
        }
        // 跳出 while 循环时，恰好是满足 charArray[left] != charArray[right]
        // 对于回文字符串长度 right - left + 1 - 2
        return right - left - 1;
    }

    /**
     * 判读是否是回文子串
     *
     * @param charArray
     * @param left
     * @param right
     * @return
     */
    private static boolean validPalindromic(char[] charArray, int left, int right) {
        while (left < right) {
            if (charArray[left] != charArray[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(longestPalindrome1("babad"));
        System.out.println(longestPalindrome1("cbbd"));

    }
}
