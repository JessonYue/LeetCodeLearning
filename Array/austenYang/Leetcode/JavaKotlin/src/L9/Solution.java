package L9;

import com.sun.org.apache.bcel.internal.generic.IF_ACMPEQ;

public class Solution {
    public static boolean isPalindrome1(int x) {
        String value = String.valueOf(x);
        char[] charArray = value.toCharArray();
        int left = 0;
        int right = charArray.length - 1;
        while (left < right) {
            if (charArray[left] != charArray[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    public static boolean isPalindrome2(int x) {
        String value = String.valueOf(x);
        char[] charArray = value.toCharArray();
        int length = charArray.length;
        int left;
        int right;
        if (length % 2 == 0) {
            left = length / 2 - 1;
            right = length / 2;
        } else {
            left = right = length / 2;
        }

        while (left >= 0 && right < length) {
            if (charArray[left] != charArray[right]) {
                return false;
            }

            left--;
            right++;
        }

        return true;


    }

    public static boolean isPalindrome3(int x) {
        int original = x;
        int ans = 0;
        if (x < 0) {
            return false;
        }
        while (x != 0) {
            if (ans * 10 / 10 != ans) { // 判断 一个值是否越界
                return false;
            }

            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return ans == original;
    }

    public static void main(String[] args) {
        boolean palindrome3 = isPalindrome3(1000000001);
        System.out.println(palindrome3);
    }

}
