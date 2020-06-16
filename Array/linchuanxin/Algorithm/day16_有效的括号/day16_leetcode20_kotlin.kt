package day16

import java.util.*

class day16_leetcode20 {
//    companion object {
//        @JvmStatic
//        fun main(args: Array<String>) {
//            println("00000000000000")
//        }
//    }

    fun isValid(s:String):Boolean{
        var stack = Stack<Char>()
        if(s.isEmpty())
            return true;
        if(s.length % 2 != 0)
            return false;
        s.forEach {c->
            if(c == '('|| c== '[' || c == '{'){
                stack.push(c);
            }else{
                if (stack.isEmpty())
                    return false
                val topChar = stack.pop()
                if (c == ')' && topChar != '(')
                    return false
                if (c == ']' && topChar != '[')
                    return false
                if (c == '}' && topChar != '{')
                    return false
            }
        }
        return stack.isEmpty();
    }

}

fun main() {
    var day16 = day16_leetcode20()
    println(day16.isValid("{}}"));


}