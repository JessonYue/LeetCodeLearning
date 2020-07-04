#include <stdlib.h>
#include <stdio.h>

/**
 * 有序链表转换二叉搜索树给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树,
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1.
 * 这个题，还是有点不理解，后面再屡屡
 */

struct ListNode{
    int val;
    struct ListNode* next;
};

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int sizeofListNode(struct ListNode *head) {
    struct ListNode *tmp = head;
    int size = 0;
    while (tmp != NULL) {
        size += 1;
        tmp = tmp->next;
    }
    return size;
}

struct ListNode *tmpHead;

struct TreeNode *convertListToBST(int left, int right) {
    if (left > right) {
        return NULL;
    }

    int mid = (left + right) / 2;
    struct TreeNode *leftTreeNode = convertListToBST(left, mid - 1);
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = tmpHead->val;
    root->left = leftTreeNode;
    tmpHead = tmpHead->next;
    root->right = convertListToBST(mid + 1, right);
    return root;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
    tmpHead = head;
    int size = sizeofListNode(head);
    return convertListToBST(0, size - 1);
}

