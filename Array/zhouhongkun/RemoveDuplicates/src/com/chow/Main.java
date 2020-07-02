package com.chow;

import java.util.Stack;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        String str = "abbaca";
//        String res = removeDuplicates(str);
        String res = removeDuplicatesWithStack(str);
        System.out.println(res);
    }

    //循环遍历比较实现
    private static String removeDuplicates(String s) {
        boolean needRemove = false;
        int length = s.length();
        for(int i=0; i<length; i++){
            if(i+1<length){
                char c1 = s.charAt(i);
                char c2 = s.charAt(i+1);
                if(c1 == c2){
                    s = removeCharAt(s, i+1);
                    s = removeCharAt(s, i);
                    needRemove = true;
                    break;
                }
            }
        }
        if(needRemove){
            return removeDuplicates(s);
        }

        return s;
    }

    private static String removeCharAt(String s, int pos) {
        return s.substring(0, pos) + s.substring(pos + 1);
    }

    //通过栈实现
    private static String removeDuplicatesWithStack(String s){
        Stack<Character> stack = new Stack<>();
        int length = s.length();
        for(int i=0; i<length; i++){
            if(!stack.isEmpty() && stack.peek() == s.charAt(i)){
                stack.pop();
            }else{
                stack.push(s.charAt(i));
            }
        }

        StringBuilder stringBuilder = new StringBuilder();
        for (Character c : stack) {
            stringBuilder.append(c);
        }
        return stringBuilder.toString();
    }
}
