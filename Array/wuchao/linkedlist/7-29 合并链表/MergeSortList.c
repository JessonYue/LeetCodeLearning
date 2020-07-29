//
// Created by 吴超 on 2020/7/29.
//
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
void merge(struct ListNode *root,struct ListNode * left,struct ListNode* right){
    if(left==NULL&&right==NULL) return;
    if(left==NULL){
        root->next = right;
        merge(root->next,left,right->next);
        return;
    }
    if(right==NULL){
        root->next = left;
        merge(root->next,left->next,right);
        return;
    }
    if(left->val<right->val){
        root->next = left;
        left = left->next;
    } else {
        root->next = right;
        right = right->next;
    }
    merge(root->next,left,right);
    return;
}
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    merge(dummy,l1,l2);
    return dummy->next;
}

