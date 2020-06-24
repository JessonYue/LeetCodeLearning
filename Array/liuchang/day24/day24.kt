package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/24
 * @describe
 */
class day24 {
    class Node {
        var data = -1;
        var next: Node? = null;

        constructor(data: Int) {
            this.data = data
        }


        fun hasCycle(head: Node): Boolean {
            var slowNode = head;
            var fastNode = head;
            for (i in 0 until Int.MAX_VALUE) {

                slowNode = slowNode.next!!;
                fastNode = fastNode.next!!.next!!;
                if (slowNode == fastNode) {
                    return true;
                } else if (fastNode == null) {
                    return false;
                }
            }
            return false;

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