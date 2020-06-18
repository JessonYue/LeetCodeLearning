class Solution {
    //用栈实现，依次遍历字符串中的字符，如果是左括号则放入栈中，如果不是左括号则跟栈顶元素比较，如果刚好匹配（即刚好是同类型的一个左括号，一个右括号），则栈顶元素出栈。
    //知道遍历完所有字符，如果栈是空的，则所有的字符都完成了括号匹配。
    public boolean isValid(String s) {
        int stringLength = s.length();
        if(stringLength%2 != 0){
            return false;
        }
        Stack<Character> stack = new Stack<>();
        for(int i=0;i<stringLength;i++){
            char item = s.charAt(i);
            if(isLeft(item)){
                stack.push(item);
            } else {
                if(stack.isEmpty()){
                    return false;
                }
                char top = stack.peek();
                if(isMatched(top,item)){
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        if(stack.isEmpty()){
            return true;
        }
        return false;
    }

    public boolean isMatched(char a,char b){
        if(a == '{'){
            return b == '}';
        }

        if(a == '('){
            return b == ')';
        }

        if(a == '['){
            return b == ']';
        }

        return false;
    }

    public boolean isLeft(char c){
        return  c == '{' || c == '[' || c == '(';
    }
}