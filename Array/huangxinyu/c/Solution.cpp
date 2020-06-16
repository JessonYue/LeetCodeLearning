//
// Created by hasee on 2020/6/13.
//
#include "alo.h"
#include <stack>
#include <cstring>

bool isPalindrome(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *pre = head;
    ListNode *prepre = nullptr;
    while (fast != nullptr && !fast->next) {
        pre = slow;
        fast = fast->next->next;
        slow = slow->next;
        pre->next = prepre;
        prepre = pre;
    }
    if (!fast) {
        slow = slow->next;
    }
    while (slow != nullptr) {
        if (pre->val != slow->val) {
            return false;
        }
        pre = pre->next;
        slow = slow->next;
    }
    return true;
}

/**
 * 20 有效括号
 */
bool isValidBrackets(const char *s) {
    if (!s)return false;
    std::stack<char> st;
    int len = strlen(s);
//    string ss;
    for (int i = 0; i < len; i++) {
        if ('{' == *(s + i)) {
            st.push('}');
        } else if ('[' == *(s + i)) {
            st.push(']');
        } else if ('{' == *(s + i)) {
            st.push('}');
        } else if (st.empty() || *(s + i) != st.top()) {
            return false;
        } else {
            st.pop();
        }
    }
    return st.empty();
}

