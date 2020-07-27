package L844;

import java.util.Stack;

public class Solution {
    public static boolean backspaceCompare(String S, String T) {
        return build(S).equals(build(T));
    }

    private static String build(String str) {
        char[] chars = str.toCharArray();
        Stack<Character> stack = new Stack<>();
        for (char c : chars) {
            if (c != '#') {
                stack.push(c);
            } else if (!stack.isEmpty()) {
                stack.pop();
            }
        }
        StringBuilder stringBuilder = new StringBuilder();
        for (char c:stack){
            stringBuilder.append(c);
        }
        return stringBuilder.toString();
    }

    public static void main(String[] args) {
        boolean b = backspaceCompare("111#11", "111#11");
        System.out.println(b);
    }
}
