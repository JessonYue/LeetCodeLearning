package L7;

import java.util.Stack;

public class Solution {
    public static int reverse1(int x) {
        boolean fu = false;
        if (x < 0) {
            fu = true;
        }
        int absValue = Math.abs(x);
        String valueStr = String.valueOf(absValue);
        char[] charArray = valueStr.toCharArray();
        Stack<Character> stack = new Stack<>();
        for (char c : charArray) {
            stack.push(c);
        }
        while (stack.peek() == 0) {
            stack.pop();
        }
        StringBuilder stringBuilder = new StringBuilder();
        if (fu) {
            stringBuilder.append("-");
        }

        while (!stack.isEmpty()) {
            stringBuilder.append(stack.pop());
        }
        try {
            return Integer.parseInt(stringBuilder.toString());
        } catch (Exception e) {
            return 0;
        }

    }


    public static int reverse2(int x) {
        int ans = 0;
        while (x != 0){
            if (ans * 10 / 10 != ans){
                return 0;
            }
            ans = ans * 10 + x % 10;
            x = x /10;

        }
        return ans;
    }

    public static void main(String[] args) {
        reverse2(-123);
        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.MIN_VALUE);
    }
}
