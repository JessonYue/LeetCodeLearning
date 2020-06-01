package com.github.leetcode.p0009_palindrome_number;

/**
 * https://leetcode-cn.com/problems/palindrome-number/
 * <p>
 * 回文数：
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * <p>
 * 示例：
 * 示例 1:
 * <p>
 * 输入: 121
 * 输出: true
 * 示例 2:
 * <p>
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * <p>
 * 进阶:
 * 你能不将整数转为字符串来解决这个问题吗？
 * <p>
 * 时间复杂度在 O()
 */
class Solution {
    /**
     * --------------------我的代码--------------------
     */
    public boolean isPalindrome(int x) {
        //如果是负数直接返回false
        if (x == 0) {
            return true;
        }
        //优化：
        if (x < 0 || x % 10 == 0) {
            return false;
        }

        String s = x + "";
        //字符串回文的通用判断
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isPalindrome(12321));
        System.out.println(solution.isPalindrome(123321));
        System.out.println(solution.isPalindrome(12334321));
        System.out.println(solution.isPalindrome(-12321));
    }

    /**
     * --------------------别人的代码--------------------
     */

}