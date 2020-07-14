/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 不知道该说啥
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    *node = *(node->next);

    }
};