#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool backspaceCompare(string S, string T);

int main() {
    bool result = backspaceCompare("y#fo##f", "y#f#o##f");
    printf("result is %d", result);
    return 0;
}

/**
 * 思路：使用栈进行字符删除操作
 * @param S
 * @param T
 * @return
 */
bool backspaceCompare(string S, string T) {
    stack<char> stack1;
    stack<char> stack2;
    for (char s:S) {
        if (s != '#') {
            stack1.push(s);
        } else if (!stack1.empty()) {
            stack1.pop();
        } else {
            continue;
        }
    }
    for (char t:T) {
        if (t != '#') {
            stack2.push(t);
        } else if (!stack2.empty()) {
            stack2.pop();
        } else {
            continue;
        }
    }
    if (stack1.size() == stack2.size()) {
        if (stack1.size() == 0) {
            return true;
        }
        while (stack1.size() != 0) {
            if (stack1.top() == stack2.top()) {
                stack1.pop();
                stack2.pop();
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    return false;
}