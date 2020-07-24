package L102;

import Base.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
    private static List<List<Integer>> result = new ArrayList<>();
    /**
     * @param root
     * @return
     */
    public static List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return result;
        helper(root, 0);
        return result;
    }
    /**
     * 传入当前层 级
     * 层序递归遍历
     *  树的天然递归性 ，在递归是 层序 那么就加上 层序 的 level 标记
     * @param node
     * @param level
     */
    private static void helper(TreeNode node, int level) {
        if (node == null) return;
        if (result.size() == level)
            result.add(new ArrayList<>());
        result.get(level).add(node.val);
        helper(node.left, level + 1);
        helper(node.right, level + 1);
    }


    /**
     * 层序遍历模式匹配到 队列 ---> 可给队列中每一层添加虚拟分割符
     * @param root
     * @return
     */
    public static List<List<Integer>> levelOrder2(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> level = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode dummyNode = new TreeNode(-1);

        if (root != null) {
            queue.offer(root);
            queue.offer(dummyNode);
        }

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();
            if (current == dummyNode) {
                ArrayList<Integer> integers = new ArrayList<>();
                integers.addAll(level);
                result.add(integers);
                level.clear();
                if (!queue.isEmpty()) {
                    queue.offer(dummyNode);
                }
            } else {
                level.add(current.val);
                if (current.left != null) {
                    queue.offer(current.left);
                }
                if (current.right != null) {
                    queue.offer(current.right);
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        TreeNode treeNode = TreeNode.mkTree("[3,9,20,null,null,15,7]");
        List<List<Integer>> lists = levelOrder2(treeNode);
        System.out.println(lists);
    }
}
