/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 *
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点  * 的值的奇偶性。
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 *
 */
struct ListNode* oddEvenList(struct ListNode* head){
    if(head == NULL){
        return head;
    }
    struct ListNode* head1 = NULL;
    struct ListNode* firstHead2 = NULL;
    struct ListNode* head2 = NULL;
    struct ListNode* currentNode = head;
    int n = 1;
    while(currentNode){
        if(n%2){
            if(head1 == NULL){
                head1 = currentNode;
            }else{
                head1->next = currentNode;
                head1 = currentNode;
            }
        }else{
            if(head2 == NULL){
                head2 = currentNode;
                firstHead2 = currentNode;
            }else{
                head2->next = currentNode;
                head2 = currentNode;
            }
        }
        currentNode = currentNode->next;
        n++;
    }
    head1->next = firstHead2;
    if(head2){
        head2->next = NULL;
    }
    return head;

}

