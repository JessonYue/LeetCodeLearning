package com.test

import java.util.HashMap
import java.util.Stack

object Solution {
    internal var map = HashMap<Char, Char>()

    @JvmStatic
    fun main(args: Array<String>) {
        println(isValid("()"))
        println(isValid("(({}))"))
        println(isValid("(({}{{})})"))
        println(isValid("("))
    }

    private fun isValid(s: String): Boolean {
        map.put(')','(')
        map.put(']','[')
        map.put('}','{')
        val chars=s.toCharArray()
        if(chars.size%2==1) return false
        val stack=Stack<Char>()
        for (i in 0 until chars.size){
            if (map.containsKey(chars[i])) {
                val character = map.get(chars[i])
                var pop = if(stack.empty()) {'#'}  else{stack.pop()}
                if (pop != character) {
                    return false
                }
            } else {
                stack.push(chars[i])
            }
        }
        return stack.empty()
    }
}
