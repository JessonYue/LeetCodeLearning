package leetCode;

import android.support.annotation.NonNull;

import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

public class DFS {


    /*
     * Return true if there is a path from cur to target.
     */
    //使用递归实现
    boolean dfs(@NonNull Node cur, @NonNull Node target, @NonNull Set<Node> visited) {
        //1.terminal recurrence
        if (cur == target) {
            return true;
        }
        //process cur
        if (cur.left != null && !visited.contains(cur.left)) {
            visited.add(cur.left);
            // drill down
            dfs(cur.left, target, visited);
        }
        if (cur.right != null && !visited.contains(cur.right)) {
            visited.add(cur.right);
            // drill down
            dfs(cur.right, target, visited);
        }

        //reset status

        return false;
    }

    //递归解决方案的优点是它更容易实现,存在一个很大的缺点：如果递归的深度太高，将遭受堆栈溢出
    //使用 while 循环和栈来模拟递归期间的系统调用
    boolean dfs2(@NonNull Node root, @NonNull Node target) {
        Set<Node> visited = new HashSet();
        Stack<Node> stack = new Stack<>();
        stack.add(root);
        while (!stack.isEmpty()) {
            Node cur = stack.peek();
            if (cur == target) {
                return true;
            }
            if (cur.right != null &&!visited.contains(cur.right)) {
                visited.add(cur.right);
                stack.add(cur.right);
            }
            if (cur.left != null &&!visited.contains(cur.left)) {
                visited.add(cur.left);
                stack.add(cur.left);
            }
            stack.remove(cur);
        }
        return false;
    }


    //二叉树
    public class Node {
        public Node left;
        public Node right;
        int val;

        public Node(int val) {
            this.val = val;
        }
    }
}
