import java.util.Stack;

public class Solution_20 {
    public boolean isValid(String s) {
        if (s == null) return false;
        Stack<Character> stack = new Stack<>();
        for (Character character: s.toCharArray()) {
            if (character == '(') {
                stack.push(')');
            }else if (character == '[') {
                stack.push(']');
            }else if (character == '{') {
                stack.push('}');
            }else if (stack.empty() || character != stack.pop()) {
                return false;
            }
        }
        if (stack.empty()) {
            return true;
        }
        return false;
    }
}
