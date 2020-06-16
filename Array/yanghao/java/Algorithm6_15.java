package jdbc.mvc;

import java.util.List;
import java.util.Stack;

public class Algorithm6_15<V> {
	
	public static boolean isValid(String s) {
		char[] a = s.toCharArray();
		if (a.length <= 0) {
			return false;
		}
		
		if (a.length %2 == 1) {
			return false;
		}
		Stack<Character> stack = new Stack<>();
		for(int i = 0; i < s.length(); i++) {
			char theChar = s.charAt(i);
			if (theChar == '(' || theChar == '{' || theChar == '[') {
				stack.push(theChar);
			}else {
				if (stack.isEmpty()) {
					return false;
				}
				
				char preChar = stack.peek();
				if ((preChar == '{' && theChar == '}') || (preChar == '(' && theChar == ')') || (preChar == '[' && theChar == ']')) {
					stack.pop();
				}else {
					return false;
				}
			}
		}
		return stack.isEmpty();
    }
	
	public static void main(String[] args) {
		System.out.println(isValid("{}"));
	}
}
