```
109. 有序链表转换二叉搜索树
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定的有序链表： [-10, -3, 0, 5, 9],
一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
      0
     / \
   -3   9
   /   /
 -10  5

```





#### C

```c
struct TreeNode *sortedListToArray(int *pInt, int size) {
    if ((NULL == pInt) || (0 == size)) return NULL;
    int index;
    struct TreeNode *treeNode;
    treeNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    index = size / 2;
    treeNode->val = pInt[index];
    treeNode->left = sortedListToArray(&pInt[0], index);
    treeNode->right = sortedListToArray(&pInt[index + 1], size - index - 1);
    return treeNode;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
    if (head == NULL) return NULL;
    struct TreeNode *treeNode;
    struct ListNode *listNode = head;
    int *num = malloc(sizeof(int) * 2000);
    int numSize = 0;
    memset(num, 0, sizeof(int));
    while (listNode != NULL) {
        num[numSize] = listNode->val;
        listNode = listNode->next;
        numSize++;
    }
    treeNode = sortedListToArray(num, numSize);
    free(num);
    return treeNode;
}
```

