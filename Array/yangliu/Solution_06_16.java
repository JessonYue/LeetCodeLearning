import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Solution_06_16 {

    public boolean isValid(String s) {
        char[] chars = s.toCharArray();
        if (chars.length % 2 != 0) return false;
        Stack<Character> characters = new Stack<Character>();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == '{' || chars[i] == '(' || chars[i] == '[')
                characters.push(chars[i]);
            else {
                if (!characters.empty())
                    return false;

                Character peek = characters.peek();
                if (peek == '[' && chars[i] == ']' ||
                        peek == '(' && chars[i] == ')' ||
                        peek == '{' && chars[i] == '}')
                    characters.pop();
            }


        }
        return characters.empty();
    }


}
