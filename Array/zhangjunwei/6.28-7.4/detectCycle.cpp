//
// Created by 张俊伟 on 2020/7/1.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //快慢指针  第一次相遇
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (fast  == nullptr || fast->next== nullptr)return nullptr;//不是环路时 其中fast->next== nullptr是链表只有一个结点
        fast = head;
        //fast 与 slow再次 一次一步的走  再次相遇的地方即是环路的开头节点
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};