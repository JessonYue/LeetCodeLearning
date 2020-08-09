//
// Created by Vashon on 2020/8/3.
//

#include "homework_036.h"

struct ListNode *sortList_1(struct ListNode *head) {
    if (!head || !head->next) return head;
    // 寻找中间节点
    struct ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *middle = slow->next;
    slow->next = NULL;
    // 递归切割链表
    struct ListNode *leftH = sortList_1(head);
    struct ListNode *rightH = sortList_1(middle);
    // 归并排序
    // 创建头结点法，明显，创建头结点能使逻辑简洁很多
    struct ListNode newHead, *temp = &newHead;
    while (leftH && rightH) {
        if (leftH->val < rightH->val) {
            temp->next = leftH;
            leftH = leftH->next;
        } else {
            temp->next = rightH;
            rightH = rightH->next;
        }
        temp = temp->next;
    }
    temp->next = leftH ? leftH : rightH;
    return newHead.next;

    // 不创建头结点法
//    struct ListNode *temp = NULL, *newHead = NULL;
//    bool flag = false;
//    while (leftH && rightH) {
//        if (leftH->val < rightH->val) {
//            if (!temp)
//                temp = newHead = leftH;
//            else {
//                flag = true;
//                temp->next = leftH;
//            }
//            leftH = leftH->next;
//        } else {
//            if (!temp)
//                temp = newHead = rightH;
//            else {
//                flag = true;
//                temp->next = rightH;
//            }
//            rightH = rightH->next;
//        }
//        if (flag) temp = temp->next;
//    }
//    temp->next = leftH ? leftH : rightH;
//    return newHead;
}

int getLinkSize(struct ListNode *head) {
    struct ListNode *fast = head;
    int size = 0;
    while (fast && fast->next) {
        fast = fast->next->next;
        size += 2;
    }
    if (fast) return size + 1;
    else return size;
}

struct ListNode *findLinkHeadAndComputeSize(struct ListNode *head, struct ListNode **linkHead,
                                            int mergeSize, int *restSize, int *size2, bool *isBreak) {
    struct ListNode *fast = head;
    int size = *restSize;
    if (size == 1 || mergeSize > size) {    // 剩余一个节点或归并大小比剩余节点大，不需要继续寻找链 2，直接进入下轮循环
        *isBreak = true;
        return fast;
    } else {
        int mergeLinkSize = mergeSize << 1;
        if (mergeSize == 1) {   // 需要合并的链长为 1
            fast = fast->next;
            *linkHead = fast;   // 得到链 2 的头部
            fast = fast->next;
            *restSize = size - mergeLinkSize;
        } else {
            int count = mergeSize;
            while (count) {
                fast = fast->next->next;
                count -= 2;
            }
            *linkHead = fast;   // 得到链 2 的头部
            if (size >= mergeLinkSize) {    // 剩余节点数比归并链大
                count = mergeSize;
                while (count) {
                    fast = fast->next->next;
                    count -= 2;
                }
                *restSize = size - mergeLinkSize;
                *size2 = mergeSize;
            } else {
                count = size - mergeSize - 2;// 得到剩余节点数
                while (count >= 0) {
                    fast = fast->next->next;
                    count -= 2;
                }
                if (count == -1)   // 当链表是单数个节点，防止漏了一个节点的迭代
                    fast = fast->next;
                *restSize = 0;
                *size2 = size - mergeSize;
            }
        }
    }
    return fast;
}

struct ListNode *mergeAndSortLink(
        struct ListNode *head, struct ListNode *link1,
        struct ListNode *link2, struct ListNode *restLink,
        int size1, int size2) {
    struct ListNode *prior = head, *l1 = link1, *l2 = link2;
    int count1 = size1, count2 = size2;
    while (count1 > 0 && count2 > 0) {      // 归并并排序
        if (l1->val < l2->val) {
            prior->next = l1;
            l1 = l1->next;
            count1--;
        } else {
            prior->next = l2;
            l2 = l2->next;
            count2--;
        }
        prior = prior->next;
    }
    prior->next = count1 == 0 ? l2 : l1;    // 拼接两条链中余下的最大的节点
    while (count1 > 0 || count2 > 0) {
        prior = prior->next;
        count1--;
        count2--;
    }
    prior->next = restLink;
    return prior;
}

struct ListNode *sortList_2(struct ListNode *head) {
    if (!head || !head->next) return head;
    int linkSize = getLinkSize(head), mergeSize = 1;
    struct ListNode temp, *newHead = &temp, *h;
    newHead->next = head;
    while (mergeSize < linkSize) {
        newHead = &temp;
        h = newHead->next;
        int restSize = linkSize;    // 记录每次归并后剩余的节点数
        while (h != NULL) {
            struct ListNode *h1 = h, *h2;
            bool isBreak = false;
            int size2 = 1;
            h = findLinkHeadAndComputeSize(h, &h2, mergeSize, &restSize, &size2, &isBreak);
            if (isBreak) break;
            newHead = mergeAndSortLink(newHead, h1, h2, h, mergeSize, size2);
        }
        mergeSize <<= 1;    // 根据归并的思想，每次的链的大小是原来的两倍
    }
    return temp.next;
}

void homework_036_148(void) {
    // 创建链表
    Node *list = NULL;
    listInsert(&list, 4);
    listInsert(&list, 2);
    listInsert(&list, 1);
    listInsert(&list, 3);
    listInsert(&list, 7);
    listInsert(&list, 5);
    listInsert(&list, 6);
    displayList(list);
    list = sortList_1(list);
    displayList(list);
    destroyList(&list);
}