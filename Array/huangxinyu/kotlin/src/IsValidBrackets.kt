import java.util.*

fun isValidBrackets(s: String): Boolean {
    if ((s.length and 1) == 1) {
        return false
    }
    val st: Stack<Char> = Stack();
    for (c in s) {
        if ('{' == c) {
            st.push('}')
        } else if ('[' == c) {
            st.push(']')
        } else if ('(' == c) {
            st.push(')')
        } else if (st.empty() || c == st.peek()) {
            return false
        } else {
            st.pop()
        }
    }
    return st.empty()
}