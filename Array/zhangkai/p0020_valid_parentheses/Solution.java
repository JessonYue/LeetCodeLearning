package com.github.leetcode.p0020_valid_parentheses;

import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/valid-parentheses/
 * <p>
 * 有效的括号：
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 * <p>
 * 示例：
 * 输入: "()[]{}"
 * 输出: true
 * <p>
 * 时间复杂度在 O()
 */
class Solution {
    /**
     * --------------------我的代码--------------------
     */
    public boolean isValid(String s) {
        //长度是奇数直接返回false
        if (s.length() % 2 == 1) {
            return false;
        }
        if (s.length() == 0) {
            return true;
        }

        Stack<Object> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '}' || c == ']' || c == ')') {
                if (stack.empty())
                    return false;

                char pop = (char) stack.pop();
                if (c == '}') {
                    if (pop != '{') {
                        return false;
                    }
                }
                if (c == ']') {
                    if (pop != '[') {
                        return false;
                    }
                }
                if (c == ')') {
                    if (pop != '(') {
                        return false;
                    }
                }

            } else {
                stack.push(c);
            }
        }

        return stack.empty();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isValid("(()("));

        /*System.out.println(solution.isValid("([)"));
        System.out.println(solution.isValid(""));
        System.out.println(solution.isValid("()[]{}"));
        System.out.println(solution.isValid("([)]"));*/
    }

    /**
     * --------------------别人的代码--------------------
     */

}