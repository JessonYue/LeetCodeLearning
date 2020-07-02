/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


class Solution {
    private Stack<Character> mCharStack;
    private HashMap<Character, Character> mTempMap;

    public Solution(){
        mCharStack = new Stack<>();
        mTempMap = new HashMap<>();
        mTempMap.put('}','{');
        mTempMap.put(']','[');
        mTempMap.put(')','(');
    }

    public boolean isValid(String s) {
        for (int i = 0; i < s.length(); i++) {
            char item = s.charAt(i);
            if (!mCharStack.empty()) {
                Character peek = mCharStack.peek();
                if (peek == mTempMap.get(item)) {
                    mCharStack.pop();
                    continue;
                }
            }
            mCharStack.push(item);
        }
        return mCharStack.empty();
    }
}