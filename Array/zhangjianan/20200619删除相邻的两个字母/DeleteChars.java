package com.test;

import java.util.ArrayList;
import java.util.Stack;

public class DeleteChars {
    public static void main(String[] args) {
        String haystack = "abcbbcbcd";
        System.out.println(removeDuplicates(haystack));
        System.out.println(removeDuplicates1(haystack));
        System.out.println(removeDuplicates2(haystack));
    }

    public static String removeDuplicates(String s) {
        ArrayList<Character> list = new ArrayList();
        for (int i = 0; i < s.length(); i++) {
            list.add(s.charAt(i));
        }
        int i = 0;
        while (i < list.size()-1) {
            if (list.get(i) == list.get(i + 1)) {
                list.remove(i);
                list.remove(i);
                if (i!=0) {
                    i--;
                }
            } else {
                i++;
            }
        }
        StringBuilder stringBuffer=new StringBuilder();
        for (int i1 = 0; i1 < list.size(); i1++) {
            stringBuffer.append(list.get(i1));
        }
        return stringBuffer.toString();
    }
    public static String removeDuplicates1(String s) {
        StringBuilder stringBuffer=new StringBuilder();
        int sbLength=0;
        for (int i = 0; i < s.length(); i++) {
            if (sbLength!=0&&s.charAt(i) == stringBuffer.charAt(sbLength-1)) {
                stringBuffer.deleteCharAt(sbLength-- - 1);
            } else {
                stringBuffer.append(s.charAt(i) );
                sbLength++;
            }
        }
        return stringBuffer.toString();
    }
    public static String removeDuplicates2(String s) {
        Stack<Character> stack = new Stack();
        for (int i = 0; i < s.length(); i++) {
            if (!stack.empty()&&s.charAt(i) == stack.peek()) {
                stack.pop();
            } else {
                stack.push(s.charAt(i) );
            }
        }
        StringBuilder stringBuffer=new StringBuilder();
        while (!stack.empty()) {
            stringBuffer.append(stack.pop());
        }
        return stringBuffer.reverse().toString();
    }
}
