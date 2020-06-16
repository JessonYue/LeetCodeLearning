package com.chow;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        Map<Character, Character> map = new HashMap<>();
        map.put(')', '(');
        map.put(']', '[');
        map.put('}', '{');

        String str = "()[{}]";
        boolean isValid = isValidParentheses(str, map);
        System.out.println(isValid);

    }

    private static boolean isValidParentheses(String str, Map<Character, Character> map){
        int length = str.length();
        Stack<Character> stack = new Stack<>();
        for(int i=0; i<length; i++){
            Character c = str.charAt(i);
            if(map.containsKey(c)){
                if(stack.isEmpty()){
                    return false;
                } else {
                    if(stack.pop() != map.get(c)){
                        return false;
                    }
                }
            } else {
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }
}
