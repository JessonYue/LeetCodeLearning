package com.test;

public class StrStr {
    public static void main(String[] args) {
        String haystack="abcabcabcd";
        String needle="cd";
        System.out.println(strStr(haystack,needle));
        System.out.println(strStr(haystack,needle));
    }

    private static int strStr(String haystack, String needle) {
        int haystackLength = haystack.length();
        int needleLength = needle.length();
        if (needleLength==0) {
            return 0;
        }
        for (int i = 0; i < haystackLength-needleLength+1; i++) {
            if (haystack.charAt(i)==needle.charAt(0)) {
                if (needleLength==1) {
                    return i;
                }
                for (int j = 1; j < needleLength; j++) {
                    if (haystack.charAt(i+j)!=needle.charAt(j)) {
                        break;
                    }
                    if (j==needleLength-1) {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
}
