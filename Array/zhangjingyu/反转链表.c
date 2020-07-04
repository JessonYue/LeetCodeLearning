struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *pre = NULL, *nex;//pre表示新表的首结点，初始化为NULL,使新表尾端指向空，nex记录顺序遍历的下一结点
    while (head){
        nex = head -> next;//记录下一结点
        head -> next = pre;//当前遍历的结点连接pre
        pre = head;//pre指向当前结点，当前结点成为新表的首结点
        head = nex;//指向当前结点下一结点，所以nex的作用在于辅助遍历，防止断链
    }
    return pre;//返回新表首结点
}
