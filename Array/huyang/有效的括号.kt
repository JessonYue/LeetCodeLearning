class Solution {
fun isValid(s: String): Boolean {
        val stack = LinkedList<Char>()
        for (c in s) {
            when (c) {
                '(' -> stack.push(c)
                '[' -> stack.push(c)
                '{' -> stack.push(c)
                ')' -> if (stack.isNotEmpty() && stack.first == '(') stack.pop() else return false
                ']' -> if (stack.isNotEmpty() && stack.first == '[') stack.pop() else return false
                '}' -> if (stack.isNotEmpty() && stack.first == '{') stack.pop() else return false
            }
        }
        return stack.isEmpty()
    }
}
