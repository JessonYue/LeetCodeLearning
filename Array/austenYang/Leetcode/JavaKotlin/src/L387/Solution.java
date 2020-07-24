package L387;

import java.util.HashMap;
import java.util.Stack;

public class Solution {
    public int firstUniqChar(String s) {
        if (s == null) {
            return -1;
        }
        HashMap<Character, Integer> maps = new HashMap<>();
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            Integer count = maps.get(c);
            if (count == null) {
                maps.put(c, 1);
            } else {
                maps.put(c, ++count);
            }
        }

        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            Integer integer = maps.get(c);
            if (integer == 1) {
                return i;
            }
        }

        return -1;

    }

    public static void main(String[] args) {
        HashMap<Character, Integer> maps = new HashMap<>();
        maps.put('c', 1);
        maps.put('a', 1);
        maps.put('b', 1);

        Stack<Object> objects = new Stack<>();
        for (Object object : objects) {

        }
    }
}
