//给定一个有环链表，实现一个算法返回环路的开头节点。
//有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(slow!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;

}
