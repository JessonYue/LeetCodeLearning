public class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val) {
        this.val = val;
    }

    public void displayTree(TreeNode treeRoot) {
        if (treeRoot == null)
            return;
        System.out.print(String.format("%d -> ", treeRoot.val));
        displayTree(treeRoot.left);
        displayTree(treeRoot.right);
    }
}
