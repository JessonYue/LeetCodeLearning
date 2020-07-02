package com.lanfairy.md;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class ValidParentheses {

    public static void main(String[] args) {

    }
    private Map<Character, Character> map = new HashMap<>();


    public boolean isValid(String s) {
        map.put(')', '(');
        map.put('}', '{');
        map.put(']', '[');

        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                Character topEle = stack.empty() ? '#' : stack.pop();
                if (topEle!=map.get(c))
                    return false;
            } else {
                stack.push(c);
            }
        }
        return stack.isEmpty();

    }
}
