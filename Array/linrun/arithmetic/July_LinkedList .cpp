//
// Created by Administrator on 2020/7/14.

//

//Linked List 实战题目
//· https://leetcode.com/problems/reverse-linked-list/
//206. 反转链表
//反转一个单链表。

//示例:

//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* current = head;
    struct ListNode* next = head == NULL?NULL:head->next;
    while(current != NULL){
        current -> next = pre;
        pre = current;
        current = next;
        next = next == NULL?NULL:next->next;
    }
    return pre;
}

//现行链表中相邻元素交换
// https://leetcode.com/problems/swap-nodes-in-pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* first = head !=NULL?head->next:NULL;
    struct ListNode* one =head;
    struct ListNode* two =one !=NULL?one->next:NULL;
    struct ListNode* temp;
    while(one && two){
        temp = two->next;
        two->next = one;
        if(temp){
            one->next = temp->next;
        }else{
            one->next = NULL;
        }
        one = temp;
        if(one){
            two = temp->next;
        }
    }
    return first;

}

//判断是否是环形链表
// https://leetcode.com/problems/linked-list-cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

//判断是否是环形链表，并返回环的头部节点
// https://leetcode.com/problems/linked-list-cycle-ii
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    bool hasCycle = false;
    while(fast->next&&fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            hasCycle = true;
            break;
        }
    }
    if(hasCycle){
        for(fast = head;;){
            fast = fast ->next;
            slow = slow ->next;
            if(fast == slow){
                return slow;
            }
        }
    }else{
        return NULL;
    }

}

//https://leetcode.com/problems/reverse-nodes-in-k-group/
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//Example:
//Given this linked list: 1->2->3->4->5
//For k = 2, you should return: 2->1->4->3->5
//For k = 3, you should return: 3->2->1->4->5
//Note:
//Only constant extra memory is allowed.
//You may not alter the values in the list's nodes, only nodes itself may be changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* nHead = head;
    struct ListNode* pre = head;
    struct ListNode* cur;
    struct ListNode* nextN;
    struct ListNode* tail = NULL;
    struct ListNode* lastTail = NULL;
    int count = 0;
    while(pre){
        pre = pre->next;
        count++;
    }
    int currentIndex = 0;
    cur = head;
    bool isF = true;
    while((currentIndex += k)<count){
        pre = NULL;
        lastTail = tail;
        tail = cur;
        for(int i=0; i<k; i++){
            nextN = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextN;
        }
        if(lastTail){
            lastTail->next = pre;
        }
        if(isF){
            nHead = pre;
            isF = false;
        }

    }
    if(tail){
        tail->next = cur;
    }
    return nHead;

}