#define CHK_PTR(p)  do{if((p) == NULL){return NULL;}}while(0)
typedef struct ListNode node_st;

struct ListNode *detectCycle(struct ListNode *head) {
    CHK_PTR(head);
    node_st *fast, *slow;

    fast = head;
    fast = fast->next;
    CHK_PTR(fast);
    fast = fast->next;
    CHK_PTR(fast);

    slow = head;
    slow = slow->next;

    while(fast != slow)
    {
        fast = fast->next;
        CHK_PTR(fast);
        fast = fast->next;
        CHK_PTR(fast);

        slow = slow->next;
    }

    node_st *cur = head;

    while (cur != slow)
    {
        cur = cur->next;
        slow = slow->next;
    }

    return cur;
}
