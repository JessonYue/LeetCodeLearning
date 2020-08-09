package L951;

import Base.TreeNode;

public class Solution {
    /**
     * 翻转等价二叉树
     * 题目要求就是判断两棵二叉树是不是 flip Equivalent
     * 什么是 flip Equivalent?
     * 在二叉树的任意结点反转后，是否和另一棵树相等
     * 反转：任意结点的左子树和右子树交换
     *
     * @param root1
     * @param root2
     * @return
     */
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        return dfs(root1, root2);
    }

    /**
     * @param t1
     * @param t2
     * @return
     */
    private boolean dfs(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        if (t1.val != t2.val) return false;
        return (dfs(t1.left, t2.left) && dfs(t1.right, t2.right)) ||
                (dfs(t1.left, t2.right) && dfs(t1.right, t2.left));
    }
}
