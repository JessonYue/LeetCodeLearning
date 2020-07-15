/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedChild(head, NULL);
    }

        TreeNode* sortedChild(ListNode* head, ListNode* tail)
    {
        if (head == tail)
            return NULL;
        if (head->next==tail)
        {
            //如果只剩这一个元素了
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode* mid = head, *temp = head;
        //--------------------精华部分Begin-----------------------
        while (temp!=tail&&temp->next!=tail)
        {
            //一个前进一个位置,一个前进2个位置,最后mid会到中间,注意判断条件
            mid = mid->next;
            temp = temp->next->next;
        }
        //--------------------精华部分End-----------------------
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedChild(head, mid);
        root->right = sortedChild(mid->next, tail);
        return root;
    }

};