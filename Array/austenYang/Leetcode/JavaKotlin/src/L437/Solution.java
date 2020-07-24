package L437;

import Base.TreeNode;

public class Solution {

    /**
     *
     * 递归的重要思想：
     * 1.找到最简单的子问题求解，
     * 2.其他问题不考虑内在细节，只考虑整体逻辑。
     *
     * 递归：先思递归终止条件
     *
     * 这个题最重要的思维：
     * 路径不需要从结点开始，也不需要在叶子结点结束，但是路径方向必须是向下的（只能从父节点到子结点）
     * 这就要求我们只需要去求三部分即可：
     * 1.当前结点为根结点的路径数量
     * 2.当前结点的左孩子作为头结点的路径数量
     * 3.当前结点的右孩子作为头结点的路径数量
     * @param root
     * @param sum
     * @return
     */
    public static int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        int result = pathSumNode(root, sum);
        int a = pathSum(root.left, sum);
        int b = pathSum(root.right, sum);

        return result + a + b;
    }

    /**
     * 以 node 为根结点的二叉树，
     * 路径上和为 sum 的路径总数
     * @param node
     * @param sum
     * @return
     */
    private static int pathSumNode(TreeNode node, int sum) {
        if (node == null) return 0;
        sum = sum - node.val;
        int result = sum == 0 ? 1 : 0;
        return result + pathSumNode(node.left, sum) + pathSumNode(node.right, sum);
    }

    public static void main(String[] args) {
        TreeNode node = TreeNode.mkTree("[10,5,-3,3,2,null,11,3,-2,null,1]");
        int i = pathSum(node, 8);
        System.out.println(i);
    }
}
