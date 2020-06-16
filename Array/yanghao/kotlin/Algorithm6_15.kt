package staudy

import java.util.*

class Algorithm6_15 {
    fun isValid(s: String): Boolean {
        if (s.length % 2 == 1) return false
        val stack:Stack<Char> = Stack()
        s.toCharArray().forEach{c ->
            if (c == '{' || c == '[' || c == '('){
                stack.push(c)
            }else{
                if (stack.isEmpty()){
                    return false
                }

                val preChar = stack.peek()
                if ((preChar == '{' && c == '}') || (preChar == '(' && c == ')') || (preChar == '[' && c == ']')) stack.pop()
                else return false
            }
        }
        return stack.isEmpty()
    }

}

fun main(args: Array<String>) {
    print(Algorithm6_15().isValid("{}"))
}