/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(!head) return NULL;
    struct ListNode* cur = head;
    struct ListNode* end = head->next;
    struct ListNode* last = end;
    while(end && end->next) {
        cur->next = end->next; // 奇数节点的next等于下一个奇数节点
        cur = cur->next;
        end->next = cur->next; // 偶数节点的next等于下一个偶数节点
        end = end->next;
    }
    cur->next = last;
    return head;
}