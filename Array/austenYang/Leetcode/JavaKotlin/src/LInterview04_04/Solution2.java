package LInterview04_04;

import Base.TreeNode;
import SwordOffer59.MaxQueue;

public class Solution2 {
    private static boolean flag = true;

    public static boolean isBalanced(TreeNode root) {
        dsf(root);
        return flag;
    }

    /**
     * 返回当前节点的 深度
     *
     * @param node
     * @return
     */
    private static int dsf(TreeNode node) {
        if (node == null || !flag) return 0;
        int leftDepth = dsf(node.left) + 1;
        int rightDepth = dsf(node.right) + 1;
        if ((Math.abs(leftDepth - rightDepth) > 1)) {
            flag = false;
        }
        return Math.max(leftDepth,rightDepth);
    }

    public static void main(String[] args) {
        System.out.println(isBalanced(TreeNode.mkTree("[3,9,20,null,null,15,7]")));
        System.out.println(isBalanced(TreeNode.mkTree("[1,2,2,3,3,null,null,4,4]")));
    }
}
