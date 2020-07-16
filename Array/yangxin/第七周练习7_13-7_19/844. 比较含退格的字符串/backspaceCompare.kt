class Solution {
    fun backspaceCompare(S: String, T: String): Boolean {
        val stack1: Stack<Char> = Stack()
        val stack2: Stack<Char> = Stack()
        for (c in S) {
            if (c == '#') {
                if (stack1.isNotEmpty()) stack1.pop()
            } else {
                stack1.push(c)
            }
        }

        for (c in T) {
            if (c == '#') {
                if (stack2.isNotEmpty()) stack2.pop()
            } else {
                stack2.push(c)
            }
        }

        if (stack1.size != stack2.size) {
            return false
        }
        while (stack1.isNotEmpty()) {
            if (stack1.pop() != stack2.pop()) {
                return false
            }
        }
        return true
    }
}