package L102;

import Base.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution2 {

    /**
     * 层序遍历
     * 利用队里 加 层级屏障
     *
     * @param root
     * @return
     */
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new LinkedList<>();
        List<Integer> level = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode dividerNode = new TreeNode(1);
        if (root != null) {
            queue.offer(root);
            queue.offer(dividerNode);
        }
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node == dividerNode) {
                ArrayList<Integer> temp = new ArrayList<>();
                temp.addAll(level);
                result.add(temp);
                level.clear();
                if (!queue.isEmpty()) {
                    queue.offer(dividerNode);
                }
            } else {
                level.add(node.val);
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
        }

        return result;

    }
}
