#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head);

int main() {
    // 双指针
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;
    bool result = isPalindrome(a);
    printf("value is %d",result);
    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}

/**
 * 思路：
 * 1、利用快慢指针找到中间的节点；
 * 2、翻转链表的后半部分；
 * 3、对比链表的前半部分和后半部分是否一致
 * @param head
 * @return
 */
bool isPalindrome(ListNode* head) {
    if(head == nullptr){
        return true;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast->next){
        fast = fast -> next -> next;
        slow = slow->next;
    }
    ListNode* pre = nullptr;
    while(slow ){
        ListNode* temp = slow->next;
        slow->next = pre;
        pre = slow;
        slow = temp;
    }
    while(pre && head){
        if(pre->val != head->val){
            return false;
        }
        pre = pre->next;
        head = head->next;
    }
    return true;
}
