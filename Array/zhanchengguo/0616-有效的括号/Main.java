package com.hlg.daydaytobusiness;

import android.util.Log;

import java.util.Stack;

public class Main {

    void main() {
        boolean result = isValid("()[]{}[");
        Log.e("test", "value is " + result);
    }

    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if ('(' == c || '[' == c || '{' == c) {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char top = stack.peek();
                stack.pop();
                if (('(' == top && c != ')') ||
                        ('[' == top && c != ']') ||
                        ('{' == top && c != '}')) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}
