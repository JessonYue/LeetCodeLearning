package com.slow.lib.practice.tree;

/**
 * 二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。
 *
 * 返回转换后的单向链表的头节点。
 *
 * 思路是递归实现。先递归遍历左子树，直到找到最左边的节点，即最小的节点。
 * 将左节点的right 指向 它的父节点，右节点不动。这样就形成了一个子链表，返回这个链表的头部，即左节点。注意，遍历左子树的时候需要断开左节点，即root.left = null，否则会产生循环
 * 再就进入了递归左子树的归的过程，将返回的子链表的尾部节点的right指向root，然后递归右子树，递归左子树的过程相似，找到右子树得到的链表的头部，root的right指向遍历右子树得到的子链表的头部
 * 这样就将二叉搜索树变成了一个链表。
 * 注意，需要在左递归完成的时候，保存一下头结点，如果左子树为空，则头结点就是root结点。
 * 最后返回头结点即可。
 * @Author wuchao
 * @Date 2020/7/13-9:58 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class BSTConvertToLinkedList {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public TreeNode convertBiNode(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode left = root.left;
        root.left = null;
        TreeNode leftChildHead = convertBiNode(left);
        TreeNode head = leftChildHead;
        if (head == null) {
            head = root;
        } else {
            while (leftChildHead.right != null) {
                leftChildHead = leftChildHead.right;
            }
            leftChildHead.right = root;
        }
        TreeNode rightChildHead = convertBiNode(root.right);
        root.right = rightChildHead;
        return head;
    }
}
