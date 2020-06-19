#include <iostream>
#include <stack>
#include <list>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char c:S) {
            if (!st.empty() && c == st.top()) {
                st.pop();
                continue;
            }
            st.push(c);
        }
        string reslut;
        while (!st.empty()) {
            reslut = st.top() + reslut;
            st.pop();
        }
        return reslut;
    }
};

int main() {
    Solution *solution = new Solution();
    string s = solution->removeDuplicates("abbaca");
    printf("str is %s", s.c_str());
}

