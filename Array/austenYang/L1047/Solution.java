package L1047;

import java.util.Stack;

public class Solution {

    //"abbaca" "ca"
    public static String removeDuplicates(String S) {
        Stack<Character> stack = new Stack<>();
        stack.push(S.charAt(0));
        for (int i = 1; i < S.length(); i++) {
            char c = S.charAt(i);
            Character peek = null;
            if (!stack.isEmpty()) {
                peek = stack.peek();
            }
            if (peek != null && peek == c) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (Character character : stack) {
            sb.append(character);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        String abbaca = removeDuplicates("abbaca");
        System.out.println(abbaca);
    }
}
