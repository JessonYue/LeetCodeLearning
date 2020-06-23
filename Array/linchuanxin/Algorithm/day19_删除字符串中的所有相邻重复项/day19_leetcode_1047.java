package day19;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

public class day19_leetcode_1047 {

    //a   b   b   a  c   a
    //双端队列
    public static String removeDuplicates(String s) {
        Deque<Character> deque = new LinkedList<>();
        String res = "";
        if(s.length() > 1){
            for (int i = 0; i < s.length(); i++) {
                if(deque.isEmpty()){
                    deque.add(s.charAt(i));
                }else{
                    if(deque.getLast() == s.charAt(i) && !deque.isEmpty()){
                        deque.removeLast();
                    }else{
                        deque.add(s.charAt(i));
                    }
                }
            }
            //System.out.println(deque.getLast());
            while (!deque.isEmpty()){
                res = deque.removeLast()+res;
            }
        }else{
            res = s;
        }


        return res;
    }

    //栈实现
    public static String removeDuplicates2(String s) {
        Stack<Character> stack = new Stack<>();
        StringBuilder str = new StringBuilder();
        if(s.length() > 1){
            for (int i = 0; i < s.length(); i++) {
                if(stack.isEmpty()){
                    stack.add(s.charAt(i));
                }else{
                    if(s.charAt(i) == stack.peek()){
                        stack.pop();
                    }else{
                        stack.push(s.charAt(i));
                    }
                }
            }
            for (Character c : stack) {
                str.append(c);
            }
        }
        return str.toString();
    }

    public static void main(String[] args) {
        System.out.println(removeDuplicates2("abbaca"));
    }
}
