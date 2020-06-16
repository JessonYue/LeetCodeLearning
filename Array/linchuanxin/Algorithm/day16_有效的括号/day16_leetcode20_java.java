package day16;

import java.util.Stack;

public class day16_leetcode20_java{

    public static void main(String[] args) {
        if(isValid("{}")){
            System.out.println("chengli");
        }else{
            System.out.println("buchengli");
        }
    }

    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == '(' || c == '[' || c == '{'){
                stack.push(c);
            }else{
                if(stack.isEmpty())
                    return false;
                Character topChar = stack.pop();
                if(c == ')' && topChar != '(')
                    return false;
                if(c == ']' && topChar != '[')
                    return false;
                if(c == '}' && topChar != '{')
                    return false;
            }
        }

        return stack.isEmpty();
    }
}
