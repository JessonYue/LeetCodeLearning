class Solution {
    public String removeDuplicates(String S) {
        if(S == null || S.length() == 0) return null;
        StringBuilder sb = new StringBuilder(); // 相当于栈
        int sbLen = 0;
        for(char ch : S.toCharArray()) {
            if(sbLen != 0 && ch == sb.charAt(sbLen - 1)) {
                // 栈顶元素与当前元素相等，出栈
                sb.deleteCharAt(sbLen - 1);
                sbLen--;
            } else {
                sb.append(ch);
                sbLen++;
            }
        }
        return sb.toString();
    }
}