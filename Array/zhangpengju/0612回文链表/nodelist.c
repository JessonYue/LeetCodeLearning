
//回文链表
void cut(struct ListNode* head,struct ListNode* cutNode);
struct ListNode* reverse(struct ListNode* head);
bool IsEqual(struct ListNode* l1,struct ListNode* l2);

bool isPalindrome(struct ListNode* head){
    if(head==NULL || head->next==NULL) return true;
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;            
        slow=slow->next;
    }
    cut(head,slow);
    if(fast!=NULL) slow=slow->next;  
    return IsEqual(head,reverse(slow));
}
void cut(struct ListNode* head,struct ListNode* cutNode){ //在slow节点，断开链表
    while(head->next!=cutNode)
        head=head->next;
    head->next=NULL;
}
struct ListNode* reverse(struct ListNode* head)  //头插法 反转链表
{
    struct ListNode* newHead=NULL;
    while(head!=NULL)
    {
        struct ListNode* nextNode=head->next;
        head->next=newHead;
        newHead=head;
        head=nextNode;
    }
    return newHead;
}
bool IsEqual(struct ListNode* l1,struct ListNode* l2){
    while(l1!=NULL && l2 !=NULL)
    {
        if(l1->val != l2->val) return false;
        l1=l1->next;
        l2=l2->next;
    }
    return true;
}