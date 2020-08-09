package L101;

import Base.TreeNode;
import algorithms4.chapter_1.Stack;

import java.util.LinkedList;
import java.util.Queue;

public class Solution2 {
    public boolean isSymmetric1(TreeNode root) {
        return isMirror(root, root);
    }

    /**
     * 以t1 t2 为根结点的二树是否是镜像
     *
     * @param t1
     * @param t2
     * @return
     */
    private boolean isMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return t1.val == t2.val && isMirror(t1.left, t2.right) && isMirror(t1.right, t2.left);
    }

    public boolean isSymmetric2(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode t1 = queue.poll();
            TreeNode t2 = queue.poll();
            if (t1 == null && t2 == null) return true;
            if (t1 == null || t2 == null) return false;
            if (t1.val != t2.val) return false;
            queue.offer(t1.left);
            queue.offer(t2.right);
            queue.offer(t1.right);
            queue.offer(t2.left);
        }
        return true;
    }


}
