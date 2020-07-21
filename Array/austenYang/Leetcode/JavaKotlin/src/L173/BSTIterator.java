package L173;

import Base.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class BSTIterator {
    private Queue<TreeNode> nodes = new LinkedList<>();

    public BSTIterator(TreeNode root) {
        midOrder(root);
    }

    /**
     * @return the next smallest number
     */
    public int next() {
        if (!hasNext()) throw new UnsupportedOperationException("");
        return nodes.poll().val;
    }

    private void midOrder(TreeNode node) {
        if (node == null) return;
        midOrder(node.left);
        nodes.add(node);
        midOrder(node.right);
    }

    /**
     * @return whether we have a next smallest number
     */
    public boolean hasNext() {
        return !nodes.isEmpty();
    }


}
