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
    string removeDuplicates(string S) {
        int len = S.length();
        stack <char> st;
        for (int i = 0; i < len; i++) {
            if (st.empty() || S[i] != st.top()) {
                st.push(S[i]);
            } else {
                st.pop();
            }
        }
        string ss = "";
        while(!st.empty()){
            ss = st.top() +ss;
            st.pop();
        }
        return ss;
    }
};