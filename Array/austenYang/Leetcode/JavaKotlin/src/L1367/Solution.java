package L1367;

import Base.ListNode;
import Base.TreeNode;

public class Solution {
    /**
     * 链表是否在树上
     *
     * @param head
     * @param root
     * @return
     */
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (root == null) return false;
        return dfs(root, head) || isSubPath(head.next, root.left) || isSubPath(head.next, root.right);
    }

    /**
     * @param node 当前匹配到的二叉树节点
     * @param head 当前匹配到的链表节点
     * @return 否有一条该节点往下的路径与 headhead 节点开始的链表匹配
     */
    private boolean dfs(TreeNode node, ListNode head) {
        // 链表已经全部匹配完，匹配成功
        if (head == null) return true;
        // 二叉树访问到了空节点，匹配失败
        if (node == null) return false;

        //当前匹配的二叉树上节点的值与链表节点的值不相等，匹配失败，返回 \textit{false}false
        if (node.val != head.val) {
            return false;
        }
        return dfs(node.right, head.next) || dfs(node.left, head.next);
    }


}
