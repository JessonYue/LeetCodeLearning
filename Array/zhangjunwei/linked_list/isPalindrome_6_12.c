//
// Created by 张俊伟 on 2020/6/12.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Data int
typedef struct ListNode_ {
    Data val;
    struct ListNode_ *next;
} ListNode;

bool isPalindrome1(ListNode *head) {
    int len = 0;
    ListNode *current = head;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    int *rever_arr = (Data *) malloc(sizeof(Data) * len);
    current = head;
    int i = len - 1;
    while (current != NULL) {
        rever_arr[i--] = current->val;
        current = current->next;
    }
    current = head;
    i = 0;
    bool is_palindrome = true;
    while (current != NULL) {
        if (current->val != rever_arr[i]) {
            is_palindrome = false;
            break;
        }
        i++;
        current = current->next;
    }
    return is_palindrome;
}


//反转链表
ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *pre = NULL;
    while (cur!=NULL){
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

//找出后半部分
ListNode *endOfFirstHalf(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool isPalindrome(ListNode *head) {
    if(head==NULL) return true;//[] 空链表也是回文链表
    ListNode *fir_half = endOfFirstHalf(head);
    ListNode *sec_half = reverseList(fir_half->next);
    ListNode *p1 = head;
    ListNode *p2 = sec_half;
    bool is_pal = true;
    while (p2!=NULL){
        if (p1->val!=p2->val)
            is_pal = false;
        p1 = p1->next;
        p2 = p2->next;
    }
    //将反转的后半部分链表 再次反转复原
    fir_half->next = reverseList(sec_half);
    return is_pal;
}
