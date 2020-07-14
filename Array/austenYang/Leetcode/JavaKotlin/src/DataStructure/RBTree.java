package DataStructure;


public class RBTree<E extends Comparable<E>> {
    private static final boolean RED = true;
    private static final boolean BLACK = false;

    public class Node {
        public E e;
        public Node left, right;
        public int N;
        public boolean color;

        public Node(E e, int n, boolean color) {
            this.e = e;
            this.left = null;
            this.right = null;
            N = n;
            this.color = color;
        }
    }


    private boolean isRed(Node node) {
        if (node == null) return BLACK;
        return node.color == RED;
    }


}
