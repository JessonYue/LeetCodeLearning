//
// Created by Administrator on 2020/7/28.
//
//https://leetcode-cn.com/problems/sort-list/
//148. 排序链表
//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

//示例 1:

//输入: 4->2->1->3
//输出: 1->2->3->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoList(struct ListNode* l1, struct ListNode* l2);

struct ListNode* sortList(struct ListNode* head){
    if(!head || !head->next){
        return head;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* pre = head;
    while(fast && fast->next){
        pre = slow;
        slow = slow ->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    return mergeTwoList(sortList(head), sortList(slow));

}


struct ListNode* mergeTwoList(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = head;
    while(l1&&l2){
        if(l1->val > l2->val){
            cur->next = l2;
            l2 = l2->next;
            cur= cur->next;
            if(!l2){
                cur->next = l1;
            }
        }else{
            cur->next = l1;
            l1 = l1->next;
            cur= cur->next;
             if(!l1){
                cur->next = l2;
            }
        }
    }
    return head->next;
}

