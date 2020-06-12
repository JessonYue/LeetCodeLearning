#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head);

ListNode* oddEvenList1(ListNode* head);

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
    ListNode *result = oddEvenList(a);
    while (result != nullptr) {
        printf("method 1 value is %d\n", result->val);
        result = result->next;
    }
    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}

/**
 * 思路：判断遍历判断奇偶性进行分别存储在不同的链表中
 * @param head
 * @return
 */
ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next || !head->next->next)
        return head;
    int i = 3;
    ListNode* originalOdd = head;
    ListNode* odd = originalOdd;
    ListNode* originalEven = head -> next;
    ListNode* even = originalEven;
    head = head -> next -> next;
    while(head != nullptr){
        if(i % 2 == 0 ){
            even ->next = head;
            even = even ->next;
        }else{
            odd->next = head;
            odd = odd->next;
        }
        i++;
        head = head->next;
    }
    even -> next = nullptr;
    odd->next = originalEven;
    return originalOdd;
}

/**
 * 思路：双指针实现
 * @param head
 * @return
 */
ListNode* oddEvenList1(ListNode* head) {
    if(!head || !head->next || !head->next->next)
        return head;
    ListNode* pre = head;
    ListNode* cur = head->next;
    while(cur && cur->next){

        ListNode* tmp=pre->next;
        pre->next=cur->next;
        cur->next=cur->next->next;
        pre->next->next=tmp;

        pre=pre->next;
        cur=cur->next;
    }
    return head;
}
