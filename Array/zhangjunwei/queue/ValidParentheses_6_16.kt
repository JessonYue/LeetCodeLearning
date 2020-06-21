package mykotlin


class Solution1 {
    /**
     * '('，')'，'{'，'}'，'['，']'
     */
    fun isValid(s: String): Boolean {
        var charArray = s.toCharArray()
        var top = -1
        var map: Map<Char, Char> = mapOf(')' to '(', '}' to '{', ']' to '[')

        for (it in charArray) {
            if (top<0){//初始化
                top=0
                charArray[top] = it

            }else{
                if (map.get(it) == charArray[top]){//出栈
                     top--
                }else{//入栈
                    charArray[++top] = it
                }
            }
        }



        return top == -1
    }

}

fun main() {
    val res = Solution1().isValid("()[]{}")
    println(res)
}