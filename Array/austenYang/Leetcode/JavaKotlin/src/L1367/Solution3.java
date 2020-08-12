package L1367;

import Base.ListNode;
import Base.TreeNode;

public class Solution3 {
    /**
     * @param head
     * @param root
     * @return
     */
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (head == null && root == null) return true;
        if (root == null) return false;

        return dfs(root, head) || isSubPath(head.next, root.right) || isSubPath(head.next, root.left);

    }

    /**
     * 以Node为根节点 --> 整棵二叉树上任意一个节点
     */
    private boolean dfs(TreeNode node, ListNode head) {
        // 树走到了叶结点下面，链表走到尾节点下一个节点，能走到这说明 肯定在树上存在一条向下的路径，
        if (node == null && head == null) return true;

        if (node == null) return false; // 树向下都走完了，链表还没完 说明 肯定不存在

        if (head == null) return true; // 走完了 存在

        if (node.val != head.val) return false;

        return dfs(node.left, head.next) || dfs(node.right, head.next);

    }

}
