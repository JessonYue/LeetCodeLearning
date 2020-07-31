//
// Created by 12 on 2020/7/30.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    //148. 排序链表
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *fast = head;
        ListNode *slow = head;

        if (fast->next->next != nullptr) {
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            }
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        ListNode p = ListNode(0);
        ListNode *tmp = &p;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                tmp->next = left;
                left = left->next;
            } else {
                tmp->next = right;
                right = right->next;
            }
            tmp = tmp->next;
        }
        tmp->next = left == nullptr ? right : left;
        return p.next;
    }
};