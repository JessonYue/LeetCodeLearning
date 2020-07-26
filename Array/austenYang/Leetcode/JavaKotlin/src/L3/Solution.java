package L3;

import java.util.HashSet;

public class Solution {
    /**
     * 滑动窗口
     *
     * @param s
     * @return
     */
    public static int lengthOfLongestSubstring(String s) {
        char[] chars = s.toCharArray();
        int n = chars.length;
        HashSet<Character> occ = new HashSet<>();
        /**
         * 在滑动窗口中
         * i 表示左指针
         * rk 表示有指正 初始值为 -1 表示 它在 子字符串的左边界的左侧，还没有开始移动
         */
        int rk = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                occ.remove(chars[i - 1]);
            }
            while (rk + 1 < n && !occ.contains(chars[rk + 1])) {
                occ.add(chars[rk + 1]);
                rk++;
            }
            ans = Math.max(ans, rk - i + 1);
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring("pwwkew"));
    }
}
