package mykotlin

import java.lang.StringBuilder

class Solution {
    fun removeDuplicates(S: String): String {
        var stack : StringBuilder = StringBuilder()
        for (ch in S) {
            if (!stack.isEmpty() && ch==stack.last()){
                stack.deleteCharAt(stack.length-1)
            }else{
                stack.append(ch)
            }
        }


        return stack.toString();
    }

}