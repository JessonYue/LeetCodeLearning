//
// Created by 张佳男 on 2020/7/2.
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

struct ListNode *createListNode(struct ListNode
                         *listnode,int data) {
    if (listnode == NULL) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = data;
        node->next = NULL;
        return node;
    } else {
        struct ListNode *node = malloc(sizeof( struct ListNode));
        node->val = data;
        node->next = NULL;
        listnode->next = node;
        return node;
    }

};
struct TreeNode* newTreeNode(int x){
    struct TreeNode* node=malloc(sizeof(struct  TreeNode));
    node->val=x;
    node->left=node->right=NULL;
    return node;
}

struct ListNode *findMid(struct ListNode *pNode);

struct TreeNode *sortedListToBST(struct ListNode *head) {
    if (head == NULL) return NULL;//递归出口
    if (head->next==NULL) return newTreeNode(head->val);//递归出口
    struct ListNode * premid = findMid(head);//找到中间前一个元素
    struct ListNode * mid = premid->next;//找到中间元素
    premid->next=NULL;//断开连接
    struct TreeNode* treeNode=malloc(sizeof(struct TreeNode));
    treeNode->val=mid->val;
    treeNode->left = sortedListToBST(head);
    treeNode->right=sortedListToBST(mid->next);//中间变量的下一段  到这里分成了三段  前面链表  中间元素  后面链表
    return treeNode;
}

struct ListNode *findMid(struct ListNode *pNode) {
    struct ListNode *slow= pNode,*fast=pNode,*preslow=pNode;
    while (fast != NULL && fast->next != NULL) {
        preslow=slow;
        slow = slow->next;
        fast=fast->next->next;
    }
    return preslow;
}

void prefacePrintTree(struct TreeNode * treeNode){
    if (treeNode==NULL) return;
    printf("%d", treeNode->val);
    prefacePrintTree(treeNode->left);
    prefacePrintTree(treeNode->right);
}
void middlePrintTree(struct TreeNode * treeNode){
    if (treeNode==NULL) return;
    prefacePrintTree(treeNode->left);
    printf("%d", treeNode->val);
    prefacePrintTree(treeNode->right);
}
void afterwordPrintTree(struct TreeNode * treeNode){
    if (treeNode==NULL) return;
    prefacePrintTree(treeNode->left);
    prefacePrintTree(treeNode->right);
    printf("%d", treeNode->val);
}