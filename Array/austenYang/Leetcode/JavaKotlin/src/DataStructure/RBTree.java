package DataStructure;


public class RBTree<E extends Comparable<E>> {
    private static final boolean RED = true;
    private static final boolean BLACK = false;
    private Node root;

    public class Node {
        public E e;
        public Node left, right;
        public int N;
        /**
         * 指向该结点链接的颜色，思考2-3树：完美平衡
         */
        public boolean color;

        public Node(E e, int n, boolean color) {
            this.e = e;
            this.left = null;
            this.right = null;
            N = n;
            this.color = color;
        }
    }


    /**
     * 测试一个连接是不是 红结点
     *
     * @param node
     * @return
     */
    private boolean isRed(Node node) {
        if (node == null) return BLACK;
        return node.color == RED;
    }


    /**
     * 有一条红色的右链接 --> 要将其转换为 左链接 这个操作叫做 --> 左旋转
     * <p>
     * 方法的参数，接受一个指向红黑树中的某个结点的链接作为参数，
     * 假设被指向的节点的右链接是红色，这个方法会对数进行调整，
     * 并返回一个指向包含同一组键的子树且其左链接为红色的根节点的链接
     *
     * @param node
     * @return
     */
    private Node rotateLeft(Node node) {
        Node x = node.right;
        node.right = x.left;
        x.left = node;
        x.color = node.color;
        node.color = RED;
        x.N = node.N;
        node.N = 1 + size(node.left) + size(node.right);
        return x;
    }

    private Node rotateRight(Node node) {
        Node x = node.left;
        node.left = x.right;
        x.right = node;
        x.color = node.color;
        node.color = RED;
        x.N = node.N;
        node.N = 1 + size(node.left) + size(node.right);
        return x;
    }

    private int size(Node x) {
        if (x == null) return 0;
        else return x.N;
    }


    public void put(E e) {
        root = put(root, e);
        root.color = BLACK;
    }

    private Node put(Node node, E e) {
        if (node == null) {
            return new Node(e, 1, RED);
        }

        int cmp = e.compareTo(node.e);
        if (cmp > 0) {
            node.right = put(node.right, e);
        } else if (cmp < 0) {
            node.left = put(node.left, e);
        } else {
            node.e = e;
        }

        if (isRed(node.right) && !isRed(node.left)) {
            node = rotateLeft(node);
        }

        if (isRed(node.left) && isRed(node.left.left)) {
            node = rotateRight(node);
        }

        if (isRed(node.left) && isRed(node.right)) {
            flipColors(node);
        }
        return node;
    }

    private void flipColors(Node node) {
        node.left.color = BLACK;
        node.right.color = BLACK;
        node.color = RED;
    }

}
