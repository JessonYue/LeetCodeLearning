package com.slow.lib.practice.stack;

import java.util.Stack;

/**
 * @Author wuchao
 * @Date 2020/6/19-9:20 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class RemoveDuplicatesSolution {
    public String removeDuplicates(String S) {
        int stringLength = S.length();
        Stack<Character> stack = new Stack<>();
        int i = 0;
        while(i<stringLength){
            char item = S.charAt(i);
            if(stack.isEmpty()){
                stack.push(item);
            } else {
                if(stack.peek()==item){
                    stack.pop();
                }else{
                    stack.push(item);
                }
            }
            i++;
        }
        StringBuilder result = new StringBuilder();
        for(Character item:stack){
            result.append(item);
        }
        return result.toString();
    }
}
