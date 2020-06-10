#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = NULL;
        ListNode *pre = head;
        while (pre != nullptr){
            ListNode *temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};