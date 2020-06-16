public class Homework_012 {

    // 有效的括号，LeetCode第20题
    void homework_012_020() {
        String s = "(([{}]))";
        if (isValid(s))
            System.out.println("success");
        else
            System.out.println("failure");
    }

    private boolean isValid(String s) {
        if (s == null || s.equals(""))
            return true;
        int top = -1, length = s.length();
        if ((length & 1) == 1) {
            return false;
        }
        char[] stack = new char[length];
        for (int i = 0; i < length; i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{' ) {
                stack[++top] = s.charAt(i);
            }
            if (top == -1)
                return false;
            if (s.charAt(i) == ')') {
                if (stack[top] == '(')
                    top--;
                else
                    return false;
            }
            if (s.charAt(i) == ']') {
                if (stack[top] == '[')
                    top--;
                else
                    return false;
            }
            if (s.charAt(i) == '}') {
                if (stack[top] == '{')
                    top--;
                else
                    return false;
            }
        }
        return top == -1;
    }
}
