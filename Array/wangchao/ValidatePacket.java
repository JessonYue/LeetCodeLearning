package com.example.alg_lib.stack;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/**
 * 有效括号问题 https://leetcode-cn.com/problems/valid-parentheses/
 * */
public class ValidatePacket {

    Map<Character, Character> map = null;
    public ValidatePacket(){
        //定义map主要是方便管理
        map = new HashMap<Character, Character>();
        map.put(')', '(');
        map.put('}', '{');
        map.put(']', '[');
    }

    /**
     * 遇到开括号直接入栈，闭括号就要pop并做检查,经过入栈和弹栈后，最后的stack肯定是空的，否则就是无效
     * */
    public boolean isValidate(String s){
        if (s == null)return false;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            //闭括号 pop做检查
            if (map.containsKey(c)){
               char tmp = stack.pop();
               if (tmp != map.get(c)){
                   return false;
               }
            }else {//开括号 直接入栈
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }

}
