package com.example.kotlinproject;

public class Main {

    void main() {
        Solution solution = new Solution();
        String s = solution.removeDuplicates("abbaca");

    }
}

class Solution {
    public String removeDuplicates(String S) {
        StringBuilder sb = new StringBuilder();
        int currentPos = 0;
        for (int i = 0; i < S.length(); i++) {
            if (currentPos != 0 && S.charAt(i) == sb.charAt(currentPos - 1)) {
                sb.deleteCharAt(currentPos - 1);
                currentPos--;
            } else {
                sb.append(S.charAt(i));
                currentPos++;
            }
        }
        return sb.toString();
    }
}
