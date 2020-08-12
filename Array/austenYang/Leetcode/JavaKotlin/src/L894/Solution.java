package L894;

import Base.TreeNode;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    /**
     * 构建满二叉树
     *
     * @param N
     * @return
     */
    public List<TreeNode> allPossibleFBT(int N) {
        if ((N & 1) == 0) return new ArrayList<>(0);
        List<TreeNode> list = new ArrayList<>();
        if (N == 1) {
            list.add(new TreeNode(0));
            return list;
        }
        for (int i = 1; i <= N - 2; i += 2) {
            List<TreeNode> left = allPossibleFBT(i);
            List<TreeNode> right = allPossibleFBT(N - 1 - i);
            for (TreeNode nodeL : left) {
                for (TreeNode nodeR : right) {
                    TreeNode root = new TreeNode(0);
                    root.left = nodeL;
                    root.right = nodeR;
                    list.add(root);
                }
            }
        }
        return list;

    }
}
