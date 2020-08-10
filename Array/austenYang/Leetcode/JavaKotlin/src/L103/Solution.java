package L103;

import Base.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        LinkedList<Integer> level_list = new LinkedList<Integer>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        TreeNode dividerNode = new TreeNode(-1);
        queue.offer(root);
        queue.offer(dividerNode);
        boolean is_order_left = true;

        while (!queue.isEmpty()) {
            TreeNode curTreeNode = queue.poll();
            if (curTreeNode == dividerNode) {
                result.add(level_list);
                level_list = new LinkedList<>();

                if (!queue.isEmpty()) {
                    queue.offer(dividerNode);
                }
                is_order_left = !is_order_left;

            } else {
                if (is_order_left) {
                    level_list.addLast(curTreeNode.val);
                } else {
                    level_list.addFirst(curTreeNode.val);
                }
                if (curTreeNode.left != null) queue.offer(curTreeNode.left);
                if (curTreeNode.right != null) queue.offer(curTreeNode.right);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        TreeNode treeNode = TreeNode.mkTree("[1,2,3,4,null,null,5]");
        List<List<Integer>> lists = zigzagLevelOrder(treeNode);
        System.out.println(lists);
    }
}
