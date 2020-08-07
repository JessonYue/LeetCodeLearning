package day64_0803_leetcode20;

import java.util.Stack;

public class day64_leetcode20 {

    public boolean isValid(String s) {
        if(s.length() == 0)
            return true;
        Stack<Character> stack = new Stack();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == '['|| c == '{' || c == '(')
                stack.push(c);
            else{
                Character pop = stack.pop();
                if(pop != '(' && c == ')')
                    return false;
                if(pop != '[' && c == ']')
                    return false;
                if(pop != '{' && c == '}')
                    return false;
            }
        }
        return stack.isEmpty();
    }
}
