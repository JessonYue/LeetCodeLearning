package L173;

import Base.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class BSTIterator2 {
    private Queue<TreeNode> treeNodes = new LinkedList<>();

    public BSTIterator2(TreeNode root) {
        midOrder(root);
    }

    /**
     * @return the next smallest number
     */
    public int next() {
        if (!hasNext()) throw new UnsupportedOperationException("");
        return treeNodes.poll().val;
    }

    private void midOrder(TreeNode node) {
        if (node == null) return;
        midOrder(node.left);
        treeNodes.offer(node);
        midOrder(node.right);
    }

    /**
     * @return whether we have a next smallest number
     */
    public boolean hasNext() {
        return !treeNodes.isEmpty();
    }

}
