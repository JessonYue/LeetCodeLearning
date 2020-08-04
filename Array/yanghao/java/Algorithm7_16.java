package com.example.bsdiff;

import java.util.Stack;

/**
 * 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

	注意：如果对空文本输入退格字符，文本继续为空。

	示例 1：

		输入：S = "ab#c", T = "ad#c"
		输出：true
		解释：S 和 T 都会变成 “ac”。

	示例 2：

		输入：S = "ab##", T = "c#d#"
		输出：true
		解释：S 和 T 都会变成 “”。
		
	示例 3：

	输入：S = "a##c", T = "#a#c"
	输出：true
	解释：S 和 T 都会变成 “c”。
	
	示例 4：

	输入：S = "a#c", T = "b"
	输出：false
	解释：S 会变成 “c”，但 T 仍然是 “b”。
 * @author yanghao
 *
 */
public class Algorithm7_16 {

	public boolean backspaceCompare(String S, String T) {
        return build(S).equals(build(T));
    }

    public String build(String S) {
        Stack<Character> ans = new Stack();
        for (char c: S.toCharArray()) {
            if (c != '#')
                ans.push(c);
            else if (!ans.empty())
                ans.pop();
        }
        return String.valueOf(ans);
    }

}
