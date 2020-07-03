package day19

import java.lang.StringBuilder
import java.util.*


fun removeDuplicates(s: String): String {

    var stack = Stack<Char>()
    var sb = StringBuilder();
    if(s.length>1){
        s.forEach {c ->
            if(stack.isEmpty()){
                stack.push(c)
            }else{
                if(stack.peek() == c){
                    stack.pop()
                }else{
                    stack.push(c)
                }
            }
        }
        stack.forEach {
            sb.append(it)
        }
        return sb.toString()
    }else{
        return s;
    }

}


fun main() {
    println(removeDuplicates("abbaca"));
}