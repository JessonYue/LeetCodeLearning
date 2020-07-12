//
// Created by 张俊伟 on 2020/7/11.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head== nullptr)return head;
        ListNode **fast = &head;
        ListNode *slow = head;
        ListNode *pre = nullptr;
        int len = 0;
        while (slow) {
            len++;
            slow = slow->next;
        }
        //k%len==0 链表右移动了一遍位置相当于没有移动
        if(len==1 || k%len==0)return head;
        slow = head;
        //进行取模操作  避免 k 值过大时 时间超限
        int i =  k%len;

        while (i > 0 && *fast != nullptr) {
            i--;
            fast = &(*fast)->next;
        }
        while (*fast) {
            fast = &(*fast)->next;
            pre = slow;
            slow = slow->next;
        }
        //*fast 为 null 时
//        if (pre && pre->next) {
            *fast = head;
            pre->next = nullptr;
//        }
        return slow;
    }
};