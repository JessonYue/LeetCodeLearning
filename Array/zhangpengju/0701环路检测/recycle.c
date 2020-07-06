//【算法思路】快慢指针。经典的环路查询问题。  参考力扣解法
//1.设置快慢指针
//2.找到第一次相遇
//3.再出发慢指针
//4.相遇即所求
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
