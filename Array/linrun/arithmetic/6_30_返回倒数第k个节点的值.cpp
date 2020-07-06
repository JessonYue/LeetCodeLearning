//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
//
//注意：本题相对原题稍作改动
//
//示例：
//
//输入： 1->2->3->4->5 和 k = 2
//输出： 4
//链接：https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int kthToLast(struct ListNode* head, int k){
    struct ListNode* pre = NULL;
    struct ListNode* current = head;
    struct ListNode* next = head == NULL?NULL:head->next;
    while(current){
        current->next = pre;
        pre = current;
        current = next;
        next = next == NULL?NULL:next->next;
    }
    int i = 0;
    current = pre;
    while(current&&++i<k){
        current = current->next;
    }
    if(current){
        return current->val;
    }
    return -1;
}

