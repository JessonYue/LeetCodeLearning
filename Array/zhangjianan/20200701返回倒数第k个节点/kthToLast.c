/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
方法一
*/

int kthToLast(struct ListNode* head, int k){
    int size=0;
    struct ListNode* curent=head;
    while(curent!=NULL){
        curent=curent->next;
        size++;
    }
    int i=0;
     curent=head;
    while(curent!=NULL){
        if(size-k==i){
            return curent->val;
        }
        curent=curent->next;
        i++;
    }
    return -1;
}
/**
方法二
*/
int kthToLast(struct ListNode* head, int k){
    struct ListNode* curent=head;
    while(k--){
        curent=curent->next;
    }
    while(curent!=NULL){
        curent=curent->next;
        head=head->next;
    }
    return head->val;
}