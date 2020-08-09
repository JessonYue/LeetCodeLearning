package L124;

import Base.TreeNode;
import SwordOffer59.MaxQueue;

public class Solution {

private int maxSum = 0;
    /**
     * 求出 node 节点的最大贡献值
     *
     * @param node
     * @return
     */
    private int maxGain(TreeNode node) {
        if (node == null) return 0;
        int leftGain = Math.max(maxGain(node.left), 0);
        int rightGain = Math.max(maxGain(node.right), 0);


        int priceNewPath = node.val + leftGain + rightGain;
        maxSum = Math.max(maxSum,priceNewPath);

        return node.val + Math.max(leftGain,rightGain);

    }
}
