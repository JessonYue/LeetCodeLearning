package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/24
 * @describe
 */
class day25 {
    class Node {
        var data = -1;
        var next: Node? = null;

        constructor(data: Int) {
            this.data = data
        }


        fun hasCycle(head: Node): Int {
            var count = -1;
            var slowNode = head;
            var fastNode = head;
            if (head.next == null) {
                return count;
            }
            for (i in 0 until Int.MAX_VALUE) {

                slowNode = slowNode.next!!;
                if (fastNode.next!!.next != null) {
                    fastNode = fastNode.next!!.next!!;
                } else {
                    return -1;
                }
                if (slowNode == fastNode) {
                    return count;
                } else if (fastNode == null) {
                    return count;
                } else {
                    count++;
                }
            }
            return count;
        }

    }
    fun main(args: Array<String>) {
        var node1 = Node(3);
        var node2 = Node(2);
        node1.next = node2;
        var node3 = Node(0);
        node2.next = node3;
        var node4 = Node(4);
        node3.next = node4;
//        node4.setNext(node2);
        System.out.println("=====" + node1.hasCycle(node1));
    }
}