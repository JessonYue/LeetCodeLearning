#include <iostream>
#include "stack"
#include "string"

using namespace std;

bool isValid(string s);

int main() {
    bool result = isValid("()[]{}");
    printf("result is %d\n", result);
    return 0;
}

/**
 * 思路：
 * 1.遇到左括号则入栈；
 * 2.遇到右括号：
 * 如果栈为空，则非法；
 * 栈顶元素出栈，且判断是否和当前元素匹配；如果不匹配则非法；
 * @return
 */
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            char c_top = st.top();
            st.pop();
            if ((c_top == '(' && c != ')') ||
                (c_top == '{' && c != '}') ||
                (c_top == '[' && c != ']')) {
                return false;
            }
        }
    }
    if (!st.empty()) {
        return false;
    }
    return true;
}



