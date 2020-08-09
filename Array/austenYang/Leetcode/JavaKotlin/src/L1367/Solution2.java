package L1367;

import Base.ListNode;
import Base.TreeNode;

public class Solution2 {
    /**
     * 两次遍历二叉树
     * 1. 在树上查找与 链表头节点 head 值相同的节点，可定要遍历树查找是否有
     * 2. 第二次遍历：
     * @param head
     * @param root
     * @return
     */
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (head == null) {
            return true;
        }
        if (root == null) {
            return false;
        }
        //先判断当前的节点，如果不对，再看左子树和右子树呗
        return isSub(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
    }

    /**
     * @param head 判断以 head 为头节点的链表 是否存在向下的路径，路径上节点的值一一对应以head为头结点的链表上节点的值
     * @param node
     * @return 对与 head 节点 和 node 结点 本身来说是否相等
     */
    public boolean isSub(ListNode head, TreeNode node) {
        // 链表走到了 null 返回 true
        if (head == null) {
            return true;
        }
        // 链表没走完，树走完了 ,这肯定不行，返回false
        if (node == null) {
            return false;
        }
        //如果两个值都不同，必定不是
        if (node.val != head.val) {
            return false;
        }
        // 走到这里 当前 head 节点与node节点值相同了 ，那么再看链表的下一个节点，是否 也相同
        // 这条路径可能在做子树中的节点上 也可能在右子树的节点上，但只要有就行
        return isSub(head.next, node.left) || isSub(head.next, node.right);
    }

}
