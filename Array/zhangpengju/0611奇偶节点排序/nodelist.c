
//奇偶链表节点拼接  先找到两个头head ,然后遍历过程中分别往两个链表中放，最后偶数链表放到奇数末尾

struct ListNode{
    int val;
    struct ListNode *next;

};


struct ListNode* oddEvenList(struct ListNode* head){//dsfsdf
    //

    struct ListNode *ji, *ou, *ouHead, *temp;
    ji = head;//奇数初始化
    ou = head->next;//偶数初始化
    ouHead = ou;//记录偶数链表头，最后拼接使用
    temp = ou->next;//开始新的一轮查找分类
    while (temp){
        //偶数链表增加节点
        ou->next = ou->next->next;
        ou = ou->next;

        ji->next = temp;
        ji = ji->next;

        if(ou == NULL)break;
        temp = ou->next;
    }

    ji->next = ouHead;

    return head;


}

