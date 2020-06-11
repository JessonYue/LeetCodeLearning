#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n);

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
    ListNode *result = removeNthFromEnd(a,2);
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
 * 思路：先遍历求出链表长度，再从前往后遍历找到并删除
 * @return
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    ListNode* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    if(len == n) {
        return head -> next;
    }
    int index = len - n -1;
    temp = head;
    int i = 0;
    while(temp != NULL){
        if(i == index){
            temp->next = temp ->next -> next;
            break;
        }
        i++;
        temp = temp->next;
    }
    return head;
}
