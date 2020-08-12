package L226;

import Base.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {


    /**
     * 从上到下 交换
     *
     * @param root
     * @return
     */
    public TreeNode invertTree1(TreeNode root) {
        if (root == null) return null;
        TreeNode tempR = root.right;
        root.right = root.left;
        root.left = tempR;
        invertTree1(root.left);
        invertTree1(root.right);
        return root;

    }

    /**
     * 从下到上交换
     *
     * @param root
     * @return
     */
    public TreeNode invertTree2(TreeNode root) {
        if (root == null) return null;

        TreeNode left = invertTree2(root.left);
        TreeNode right = invertTree2(root.right);
        root.left = left;
        root.right = right;
        return root;
    }

    /**
     * 层序遍历
     *
     * @param root
     * @return
     */
    public TreeNode invertTree3(TreeNode root) {
        if (root == null) return null;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            TreeNode tempL = node.left;
            node.left = node.right;
            node.right = tempL;

            if (node.right != null) queue.offer(node.right);
            if (node.left != null) queue.offer(node.left);
        }
        return root;
    }
}
