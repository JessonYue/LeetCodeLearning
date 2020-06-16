package com.example.admin.myapplication.stack;

import org.junit.Test;

import java.util.Stack;

/**
 * create by yx
 * on 2020/6/16
 */
public class Solution {
    private Stack<Character> stack = new Stack<>();

    public boolean isValid(String s) {
        if (s == null || s.isEmpty()) {
            return true;
        }

        char[] chars = s.toCharArray();
        for (int i = 0, count = chars.length; i < count; i++) {
            if (stack.isEmpty()) {
                stack.push(chars[i]);
            } else if (stack.peek() == (chars[i] - 2) || stack.peek() == (chars[i] - 1)) {
                stack.pop();
            } else {
                stack.push(chars[i]);
            }
        }
        chars = null;
        return stack.isEmpty();
    }
}
