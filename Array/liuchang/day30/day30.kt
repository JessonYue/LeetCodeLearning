package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/30
 * @describe
 */
class day30 {

    class LinkedNode {
        var data = 0;
        var next: LinkedNode? = null;
    }

    fun reverseList(head: LinkedNode): LinkedNode {
        var node: LinkedNode = LinkedNode();
        var before: LinkedNode = LinkedNode();
        var node1 = head;
        for (i in 0 until 5) {
            var node2 = node1;
            if (node1.next != null) {
                node1 = node1.next!!;
            }
            node2.next = LinkedNode();
            if (node.data == 0 && before.data == 0) {
                node = node2;
            } else {
                before = node;
                node2.next = node;
                node = node2;
            }
        }
        return node;
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
        var node = reverseList(node1);
        for (i in 0 until 5) {
            System.out.println("=====" + node.data);
            node = node.next!!;
        }
    }

}