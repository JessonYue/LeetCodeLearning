#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '{' || c == '[' || c == '(') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                char preChar = st.top();
                if ((preChar == '{' && c == '}') ||
                    (preChar == '[' && c == ']') ||
                    (preChar == '(' && c == ')')) {
                    st.pop();

                } else {
                    return false;
                }
            }


        }
        return st.empty();
    }

};
