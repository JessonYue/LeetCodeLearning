package com.example.computerdemo;

import java.util.Stack;

public class Solution06_19 {

    class Solution {
        public String removeDuplicates(String str) {
            char[] s = str.toCharArray();
            int len = s.length;
            Stack<Character> stack = new Stack();
            for (int i = 0; i < len; i++) {
                if (stack.isEmpty() || s[i] != stack.peek()) {
                    stack.push(s[i]);
                } else {
                    stack.pop();
                }
            }
            StringBuilder sb = new StringBuilder();
            for (Character c : stack) {
                sb.append(c);
            }
            return str.toString();
        }
    }

}
