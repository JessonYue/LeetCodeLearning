import java.util.LinkedList;

public class day5 {

    /**
     *2020.06.5
     * 面试题 02.07. 链表相交 //https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/
     * 给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
     *
     *
     * 示例 1：
     *
     * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
     * 输出：Reference of the node with value = 8
     * 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
     *
     * 示例 2：
     *
     * 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
     * 输出：Reference of the node with value = 2
     * 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
     *
     * 示例 3：
     *
     * 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
     * 输出：null
     * 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
     * 解释：这两个链表不相交，因此返回 null。
     *
     * 注意：
     *
     * 如果两个链表没有交点，返回 null 。
     * 在返回结果后，两个链表仍须保持原有的结构。
     * 可假定整个链表结构中没有循环。
     * 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
     */

    /**
     * 思考思路
     * 1、首先 将数组放入链表中
     * 2、先确定在表A中 先交点的位置，如果有则继续后面的判断，如果没有，则表示没有相交点。
     * 3、继续遍历链表B 找到找到在B中位置， 如果有 进行记录 ，如果没有则表示没有相交点。
     *
     */

    public static void main(String[] args) {
        int intersect = 8;
        LinkedList linkedListA = new LinkedList();
        LinkedList linkedListB = new LinkedList();
        int[] a = {4, 1, 8, 4, 5};
        int[] b = {5, 0, 1, 8, 4, 5};
        for (int i = 0; i < a.length; i++) {
            linkedListA.add(i, a[i]);
            System.out.println(linkedListA.get(i));
        }
        for (int i = 0; i < b.length; i++) {
            linkedListB.add(i, b[i]);
        }
        for (int i = 0; i < linkedListA.size(); i++) {
            if ((int) linkedListA.get(i) == intersect) {
                for (int j = 0; j < linkedListB.size(); j++) {
                    if (linkedListA.get(i) == linkedListB.get(j)) {
                        System.out.println("在 A 中，相交节点前有 " + i + " 个节点；在 B 中，相交节点前有 " + j + " 个节点。");
                        break;
                    } else if (j == linkedListB.size()-1){
                        System.out.println("在 B 中，相交节点前有 0个 ");
                    }
                }

            } else if (i == linkedListA.size()-1){
                System.out.println("在 A 中，相交节点前有 0个 ");
            }
        }
    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
}
