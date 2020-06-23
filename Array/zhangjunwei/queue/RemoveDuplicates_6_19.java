package com.lanfairy.ndkstudy;

import java.util.ListIterator;
import java.util.Stack;

public class RemoveDuplicates {
    private Stack<Character> stack;

    public RemoveDuplicates() {
        stack = new Stack<Character>();
    }

    public String removeDuplicates(String S) {

        stack.push(S.charAt(0));
        int len = S.length();
        for (int i = 1; i < len; i++) {
            Character ch = S.charAt(i);
            if (!stack.isEmpty() && ch.compareTo(stack.peek()) == 0) {
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()){
            sb.append(stack.pop());
        }
        sb.reverse();
        return sb.toString();
    }

    public static void main(String[] args) {
        String s = "abbaca";
        String res = new RemoveDuplicates().removeDuplicates(s);
        System.out.println(res);
    }
}
