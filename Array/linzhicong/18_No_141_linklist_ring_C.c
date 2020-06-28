/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head || !head->next) return false;
    struct ListNode *first = head; // 慢指针
    struct ListNode *last = head->next->next; // 快指针

    while(first && last && last->next) {
        if(first == last) return true; // 当快指针追上慢指针，证明有环
        first = first->next;
        last = last->next->next;
    }
    return false;
}