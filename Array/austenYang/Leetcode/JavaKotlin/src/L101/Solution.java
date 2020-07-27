package L101;

import Base.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static boolean isSymmetric1(TreeNode root) {
        return isMirror(root,root);
    }
    /**
     * 两棵子树 是否镜像
     *
     * @param t1
     * @param t2
     * @return
     */
    private static boolean isMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) {
            return true;
        }
        if (t1 == null || t2 == null) {
            return false;
        }
        return (t1.val == t2.val)
                && isMirror(t1.right, t2.left)
                && isMirror(t1.left, t2.right);
    }

    public static boolean isSymmetric2(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        queue.offer(root);
        while (!queue.isEmpty()){
            TreeNode t1 = queue.poll();
            TreeNode t2 = queue.poll();
            if (t1 == null && t2 == null) continue;
            if (t1 == null || t2 == null) return false;
            if (t1.val != t2.val) return false;
            queue.offer(t1.right);
            queue.offer(t2.left);
            queue.offer(t1.left);
            queue.offer(t2.right);
        }

        return true;
    }

    public static void main(String[] args) {
        TreeNode node = TreeNode.mkTree("[1,2,2,3,4,4,3]");
        System.out.println(isSymmetric1(node));
        System.out.println(isSymmetric2(node));
    }
}
