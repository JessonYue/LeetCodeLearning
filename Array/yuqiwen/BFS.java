package leetCode;


import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;

public class BFS {


    /**
     * Return the length of the shortest path between root and target node.
     */
    int bfs(Node root, Node target) {
        Queue<Node> queue = new ArrayDeque<>();
        int step = 0;
        //1.initialize
        queue.add(root);
        //2.BFS
        while (!queue.isEmpty()) {
            step++;
            int size = queue.size();
            //3.iterate the nodes which are already in the queue
            for (int i = 0; i < size; i++) {
                Node cur = queue.peek();
                if (cur == target) {
                    return step;
                } else {  //4.add the neighbors of cur to queue;
                    queue.add(cur.left);
                    queue.add(cur.right);
                }
                //5. remove cur node
                queue.remove(cur);
            }
        }
        return -1;
    }


    //如果放入了重复的node节点 ，会导致上面的循序，下面进行优化
    int bfsOptimize(Node root, Node targt) {
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(root);
        int step = 0;
        Set<Node> used = new HashSet<>();
        while (!queue.isEmpty()) {
            Node cur = queue.peek();
            step++;
            if (cur == targt) {
                return step;
            } else {
                if (!used.contains(cur.left)) {
                    queue.add(cur.left);
                    used.add(cur.left);
                }
                if (!used.contains(cur.right)) {
                    queue.add(cur.right);
                    used.add(cur.right);
                }
            }
            queue.remove(cur);
        }

        return -1;
    }


    public class Node {
        public Node left;
        public Node right;
        int val;

        public Node(int val) {
            this.val = val;
        }
    }

}
