//
// Created by 张俊伟 on 2020/7/1.
//

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *pre = nullptr;
    struct ListNode *cur = head;
    while (cur!= nullptr){
        struct ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}