#include <stddef.h>
#include <stdlib.h>

//
// Created by 吴超 on 2020/6/29.
//
struct ListNode {
    int val;
    struct ListNode *next;
};
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode* getMiddleNode(struct ListNode* head,struct ListNode* tail);
struct TreeNode* toBST(struct ListNode* head,struct ListNode* tail);

struct ListNode* getMiddleNode(struct ListNode* head,struct ListNode* tail){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct TreeNode* toBST(struct ListNode* head,struct ListNode* tail){
    if(head==tail){
        return NULL;
    }
    struct ListNode* middleNode = getMiddleNode(head,tail);
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->left = toBST(head,middleNode);
    root->right = toBST(middleNode->next,tail);
    return root;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
    return toBST(head,NULL);
}
