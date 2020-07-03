//
// Created by Vashon on 2020/7/2.
//

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

void listInsert(struct ListNode **list, int e);

void displayList(struct ListNode *list);

// 寻找链表中间的节点
struct ListNode *findMiddleElement(struct ListNode *head);

// 链表转换成平衡二叉树
// 方法一：递归
struct TreeNode *sortedListToBST(struct ListNode *head);

// 方法二：递归 + 数组，空间换时间法
struct TreeNode *sortedListToBST_(struct ListNode *head);

// 数组转换成平衡二叉树
struct TreeNode *sortedArrayToBST(int *array, int arraySize);

// 有序链表转换二叉搜索树，LeetCode第109题
void homework_024_109(void) {
    struct ListNode *list;
    struct TreeNode *tree;
    listInsert(&list, 1);
    listInsert(&list, 2);
    listInsert(&list, 3);
    listInsert(&list, 4);
    listInsert(&list, 5);
    listInsert(&list, 6);
    listInsert(&list, 7);
    displayList(list);
    tree = sortedListToBST_(list);
    displayTree(tree);
    destroyTree(tree);
}

struct ListNode *findMiddleElement(struct ListNode *head) {
    struct ListNode *preNode = NULL, *slowNode = head, *quickNode = head;
    while (quickNode && quickNode->next) {
        preNode = slowNode;
        slowNode = slowNode->next;
        quickNode = quickNode->next->next;
    }
    if (preNode)    // 找到中间节点后，将中间节点的左边的链切断
        preNode->next = NULL;
    return slowNode;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
    if (!head)
        return NULL;
    struct ListNode *mid = findMiddleElement(head); // 找到中间的节点
    struct TreeNode *treeNode = malloc(sizeof(struct TreeNode)); // 创建一个树的叶子节点保存中间节点的值
    treeNode->val = mid->val;
    treeNode->left = treeNode->right = NULL;

    if (head == mid)    // 递归出口，当节点没有左右孩子了，也就是这个节点是叶子节点，则直接返回
        return treeNode;

    treeNode->left = sortedListToBST(head);
    treeNode->right = sortedListToBST(mid->next);
    return treeNode;
}

struct TreeNode *sortedArrayToBST(int *array, int arraySize) {
    if (!array || arraySize == 0)
        return NULL;
    int nodeIndex = arraySize / 2;
    struct TreeNode *treeNode = malloc(sizeof(struct TreeNode));
    treeNode->val = array[nodeIndex];
    treeNode->left = treeNode->right = NULL;

    if (nodeIndex == 0)
        return treeNode;

    treeNode->left = sortedArrayToBST(&array[0], nodeIndex);
    treeNode->right = sortedArrayToBST(&array[nodeIndex + 1], arraySize - nodeIndex - 1);
    return treeNode;
}

struct TreeNode *sortedListToBST_(struct ListNode *head) {
    if (!head)
        return NULL;
    int arraySize = 0, *array = NULL;
    struct ListNode *link = head;
    array = malloc(20000 * sizeof(int));
    while (link) {  // 将链表节点的数据复制到数组中去
        array[arraySize++] = link->val;
        link = link->next;
    }
    return sortedArrayToBST(array, arraySize);
}

void displayTree(struct TreeNode *tree) {
    if (!tree)
        return;
    printf("%d -> ", tree->val);
    displayTree(tree->left);
    displayTree(tree->right);
}

void destroyTree(struct TreeNode *tree) {
    if (!tree)
        return;
    destroyTree(tree->left);
    destroyTree(tree->right);
    free(tree);
    tree = NULL;
}