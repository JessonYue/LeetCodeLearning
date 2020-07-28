//
// Created by Vashon on 2020/7/27.
//

#include "ListNode.h"

void createHeadNode(ListNode *&node, int value) {
    node = new ListNode(value);
}

bool insertNode(ListNode *&head, int value) {
    assert(head != nullptr);
    ListNode *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    auto *node = new ListNode(value);
    temp->next = node;
    return true;
}

bool deleteNode(ListNode *&head, int value) {
    assert(head != nullptr);
    if (head->val == value) {   // 头节点就是要删除的节点
        ListNode *oldHead = head;
        head = head->next;
        oldHead->next = nullptr;
        delete oldHead;
        return true;
    } else {
        ListNode *pre = head, *next = head->next;
        bool isExist = false;
        while (next) {
            if (next->val == value) {
                isExist = true;
                break;
            }
            pre = next;
            next = next->next;
        }
        if (isExist) {
            pre->next = next->next;
            next->next = nullptr;
            delete next;
            return true;
        }
    }
    return false;
}

void destroyList(ListNode *&head) {
    assert(head != nullptr);
    while (head) {
        ListNode *oldHead = head;
        head = head->next;
        delete oldHead;
    }
}

void displayList(ListNode *&head) {
    assert(head != nullptr);
    ListNode *temp = head;
    while (temp->next) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << temp->val << endl;
}