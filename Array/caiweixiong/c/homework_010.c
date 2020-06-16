//
// Created by Vashon on 2020/6/12.
//

#include "list_node.h"
#include <stdio.h>

// 回文链表，LeetCode第234题
void homework_010_234(void) {
    struct ListNode *list = NULL;
    void displayList(struct ListNode *list);
    void destroyList(struct ListNode **list);
    void listInsert(struct ListNode **list, int e);
    int isPalindrome(struct ListNode *);
    listInsert(&list, 1);
    listInsert(&list, 2);
    listInsert(&list, 3);
    listInsert(&list, 3);
    listInsert(&list, 2);
    listInsert(&list, 1);
    printf("链表节点元素为： ");
    displayList(list);
    if (isPalindrome(list))
        printf("is palindrome\n");
    else
        printf("not palindrome\n");
    printf("链表节点元素为： ");
    displayList(list);
    destroyList(&list);
}

int isPalindrome(struct ListNode *head) {
    if (head == NULL || head->next == NULL) // 链表为空或者只有一个节点，都是回文
        return 1;
    struct ListNode *getListMiddle(struct ListNode *);      // 查询中点
    struct ListNode *reverseList(struct ListNode *);        // 反转链表
    int palindrome = 1; // 回文的标识
    struct ListNode *current = head, *middleNode, *reverseEndList, *reverse;
    middleNode = getListMiddle(head);    // 1->2->1 得到：2->1->null
    reverseEndList = reverseList(middleNode);// 1->2->null
    reverse = reverseEndList;
    while (reverse && palindrome) {
        if (current->val != reverse->val)
            palindrome = 0;
        current = current->next;
        reverse = reverse->next;
    }
    middleNode->next = reverseList(reverseEndList)->next;// 2->1
    return palindrome;
}

struct ListNode *getListMiddle(struct ListNode *head) {
    struct ListNode *slow = head, *quick = head;
    while (quick && quick->next) {
        quick = quick->next->next;
        slow = slow->next;
    }
    return slow;
}