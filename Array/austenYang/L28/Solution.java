package L28;

public class Solution {


    public static int strStr1(String haystack, String needle) {
        if ("".endsWith(needle)) {
            return 0;
        }
        char[] haystackCharArray = haystack.toCharArray();
        char[] needleCharArray = needle.toCharArray();
        int length = needleCharArray.length;
        char c = needleCharArray[0];
        for (int i = 0; i < haystackCharArray.length; i++) {
            char cc = haystackCharArray[i];
            if (c == cc && haystackCharArray.length - i >= length) {
                String substring = haystack.substring(i, i + length);
                if (substring.equals(needle)) {
                    return i;
                }
            }
        }
        return -1;
    }


    public static int strStr2(String haystack, String needle){
        int L = haystack.length(), n = needle.length();
        for (int i = 0; i < L - n + 1; i++) {
            if (haystack.substring(i,i + n).equals(needle)) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int index = strStr1("mississippi", "issip");
        int index1 = strStr2("mississippi", "");
        System.out.println(index);
        System.out.println(index1);
    }
}
