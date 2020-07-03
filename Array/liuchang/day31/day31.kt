package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/30
 * @describe
 */
class day31 {

    class LinkedNode {
        var data = 0;
        var next: LinkedNode? = null;
    }

    fun kthToLast(head: LinkedNode, k: Int, size: Int): Int {
        var count = 0;
        var node = head;
        while (head.next != null) {
            if (count == size - k) {
                return node.data;
            } else {
                node = node.next!!;
            }
            count++;
        }
        return -1;
    }

    fun main(args: Array<String>) {
        var node1 = LinkedNode();
        node1.data = 1;
        var node2 = LinkedNode();
        node2.data = 2;
        node1.next = node2;
        var node3 = LinkedNode();
        node3.data = 3;
        node2.next = node3;
        var node4 = LinkedNode();
        node4.data = 4;
        node3.next = node4;
        var node5 = LinkedNode();
        node5.data = 5;
        node4.next = node5;
        System.out.println("=====" + kthToLast(node1,2,5));
    }

}