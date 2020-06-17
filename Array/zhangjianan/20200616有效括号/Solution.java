package com.test;

import java.util.HashMap;
import java.util.Stack;

public class Solution {
   static HashMap<Character, Character> map = new HashMap<>();

    public static void main(String[] args) {
        System.out.println(isValid("()"));
        System.out.println(isValid("(({}))"));
        System.out.println(isValid("(({}{{})})"));
        System.out.println(isValid("("));
    }

    private static boolean isValid(String s) {
        map.put(')','(');
        map.put(']','[');
        map.put('}','{');
        char[] chars = s.toCharArray();
		 if(chars.length%2==1)return false;
        Stack<Character> stack=new Stack<Character>();
        for (int i = 0; i < chars.length; i++) {
            if (map.containsKey(chars[i])) {
                Character character = map.get(chars[i]);
                Character pop = stack.empty() ? '#' : stack.pop();
                if (pop != character) {
                    return false;
                }
            } else {
                stack.push(chars[i]);
            }
        }
        return stack.empty();
    }
}
