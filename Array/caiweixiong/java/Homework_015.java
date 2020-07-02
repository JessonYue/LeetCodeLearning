public class Homework_015 {

    // 删除字符串中的所有相邻重复项，LeetCode第1047题
    void homework_015_1047() {
        String s = "abbaca";
        s = removeDuplicates(s);
        if (s != null && s.length() != 0)
            System.out.println(String.format("filter result is : %s", s));
        else
            System.out.println("filter result is : null");
    }

    private String removeDuplicates(String S) {
        if (S == null || S.length() < 2)
            return S;
        int length = S.length(), top = -1;
        char[] chars = S.toCharArray();
        for (int i = 0; i < length; i++) {
            if (top == -1)
                chars[++top] = S.charAt(i);
            else {
                if (chars[top] == S.charAt(i))
                    top--;
                else
                    chars[++top] = S.charAt(i);
            }
        }
        if (top == -1)
            return new String("");
        else {
            char[] newStr = new char[top + 1];
            System.arraycopy(chars, 0, newStr, 0, newStr.length);
            return new String(newStr).toString();
        }
    }
}
