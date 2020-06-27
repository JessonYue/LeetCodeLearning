package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/6/26
 * @describe
 */
class day26 {

    class Node {
        var data = -1;
        var next: Node? = null;

        constructor(data: Int) {
            this.data = data
        }


        fun deleteNode(data: Int, node: Node): Node {
            var deleteNode: Node = node;
            lateinit var beforeNode: Node;
            for (i in 0 until 4) {
                if (deleteNode.data == data) {
                    beforeNode.next = deleteNode.next;
                    break;
                } else {
                    beforeNode = deleteNode;
                    if (deleteNode.next != null) {
                        deleteNode = deleteNode.next!!;
                    }
                }
            }
            return beforeNode;

        }

    }
    
    fun main(args:Array<String>){
        var node1 = Node(4);
        var node2 = Node(5);
        node1.next = node2;
        var node3 = Node(1);
        node2.next = node3;
        var node4 = Node(9);
        node3.next = node4;
//        node4.next = node2;
        var deleteNode = node1.deleteNode(5, node1);
        for (i in 0 until 3) {
            System.out.println("=====" + deleteNode.data);
            if (deleteNode.next != null) {
                deleteNode = deleteNode.next!!;

            }
        }
    }
}