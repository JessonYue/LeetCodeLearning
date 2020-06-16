class Solution {
    public boolean isValid(String s) {
        if(s == null) return false;
        int len = s.length();
        if(len == 0) return true;
        if(len % 2 == 1) return false;
        int stackLen = len / 2; // 数组长度只需要一半即可，因为括号匹配了就可以移出数组，不占空间
        char[] stack = new char[stackLen];
        int top = -1;
        for(int i = 0; i < len; i++) {
            if(s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{') {
                if(top >= (stackLen - 1)) {
                    return false;
                }
                stack[++top] = s.charAt(i);
            } else if(top == -1) {
                return false;
            } else if(s.charAt(i) == stack[top]+1 || s.charAt(i) == stack[top]+2) {
                stack[top--] = 0;
            } else {
                return false;
            }
        }
        return top == -1;
    }
}