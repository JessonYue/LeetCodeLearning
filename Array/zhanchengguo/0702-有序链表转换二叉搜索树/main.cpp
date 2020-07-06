#include <iostream>
#include "stack"
#include "string"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head);

TreeNode *buildTree(ListNode *head, ListNode *tail);

int main() {
    ListNode *a = new ListNode(-10);
    ListNode *b = new ListNode(-3);
    ListNode *c = new ListNode(0);
    ListNode *d = new ListNode(5);
    ListNode *e = new ListNode(9);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;
    TreeNode *result = sortedListToBST(a);
    printf("value is %d\n", result);
    return 0;
}

TreeNode *sortedListToBST(ListNode *head) {
    return buildTree(head, NULL);
}

/**
 * 思路：由于链表是升序，不断递归寻找中间点作为root节点
 * @param head
 * @param tail
 * @return
 */
TreeNode *buildTree(ListNode *head, ListNode *tail) {
    if (head == tail) {
        return NULL;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != tail && fast->next != tail) {
        fast = fast->next->next;
        slow = slow->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = buildTree(head, slow);
    root->right = buildTree(slow->next, tail);
    return root;
}







