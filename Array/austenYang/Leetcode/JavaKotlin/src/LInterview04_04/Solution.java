package LInterview04_04;


import Base.TreeNode;

public class Solution {
    public static boolean isBalanced(TreeNode root) {

        return dfs(root);
    }

    private static boolean dfs(TreeNode node) {
        if (node == null) {
            return true;
        }
        if (Math.abs(depth(node.left) - depth(node.right)) > 1) {
            return false;
        }
        return dfs(node.right) && dfs(node.left);
    }

    private static int depth(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return Math.max(depth(node.left), depth(node.right)) + 1;
    }


    public static void main(String[] args) {

    }

}
