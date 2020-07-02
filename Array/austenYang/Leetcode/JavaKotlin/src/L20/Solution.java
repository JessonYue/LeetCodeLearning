package L20;

import java.util.Stack;

public class Solution {

    public static boolean isValid(String s) {
        if (s != null && s.length() > 0) {
            char[] chars = s.toCharArray();
            Stack<Character> stack = new Stack<>();
            for (char c : chars) {
                if ('{' == c || '[' == c || '(' == c) {
                    stack.push(c);
                } else {
                    if (!stack.isEmpty()) {
                        char pop = stack.pop();
                        if (c != '}' && pop == '{') {
                            return false;
                        }
                        if (c != ']' && pop == '[') {
                            return false;
                        }
                        if (c != ')' && pop == '(') {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
            }
            return stack.isEmpty();
        } else {
            return true;
        }

    }


    public static boolean isValid2(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '{' || c == '[' || c == '('){
                stack.push(c);
            }else {
                if (stack.isEmpty()){
                    return false;
                }
                Character right = stack.peek();
                if (right == '{' && c == '}'){
                    stack.pop();
                }
                if (right == '[' && c == ']'){
                    stack.pop();
                }
                if (right == '(' && c == ')'){
                    stack.pop();
                }
            }
        }

        return stack.isEmpty();
    }

    public static void main(String[] args) {
        System.out.println(isValid("]"));
        System.out.println(isValid(""));
        System.out.println(isValid("[]"));
        System.out.println(isValid("[{{[([]))}}]"));
        System.out.println();
        System.out.println(isValid2("]"));
        System.out.println(isValid2(""));
        System.out.println(isValid2("[]"));
        System.out.println(isValid2("[{{[([]))}}]"));
    }
}
