package com.example.computerdemo;

import java.util.Stack;

public class Solution06_16 {

    class Solution {

        public boolean isValid(String s) {
            if (s.length() % 2 == 1) {
                return false;
            }
            Stack<Character> stack = new Stack();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '{' || c == '[' || c == '(') {
                    stack.push(c);
                } else {
                    if (stack.empty()) {
                        return false;
                    }
                    char preChar = stack.peek();
                    if ((preChar == '{' && c == '}') ||
                            (preChar == '[' && c == ']') ||
                            (preChar == '(' && c == ')')) {
                        stack.pop();

                    } else {
                        return false;
                    }
                }


            }
            return stack.empty();
        }
    }

}
