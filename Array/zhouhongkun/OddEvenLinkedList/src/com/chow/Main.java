package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        NodeList nodeList = new NodeList();
        nodeList.add(new Node(1));
        nodeList.add(new Node(2));
        nodeList.add(new Node(3));
        nodeList.add(new Node(4));
        nodeList.add(new Node(5));
        nodeList.add(new Node(6));
        nodeList.add(new Node(7));
//        nodeList.add(new Node(8));

        Node headNode = nodeList.head;
        printNode(headNode);

        Node newNode = oldEvenList(headNode);
        printNode(newNode);
    }

    /**
     * 奇偶链表
     * 思路：① 先定义两个链表 jNode  oNode
     *      ② 遍历链表，当索引为奇数时，把节点指到jNode后，当索引为偶数时，把节点指到oNode后
     *      ③ 遍历完后，再将偶数链表接在奇数链表后面
     * @param headNode
     * @return
     */
    private static Node oldEvenList(Node headNode){
        //奇链表
        Node jNode = new Node(0);
        //偶链表
        Node oNode = new Node(0);
        //移动完后的结果链表
        Node resNode = jNode;
        Node pre = oNode;
        int index = 1;
        headNode = headNode.next;
        while(headNode != null){
            if(index % 2 == 0){
                oNode.next = headNode;
                oNode = oNode.next;
            } else {
                jNode.next = headNode;
                jNode = jNode.next;
            }
            index += 1;
            headNode = headNode.next;
        }
        //说明：此处的代码是因为，当原链表节点数为奇数时，那时遍历完后，偶数链表的尾节点还是奇索引对应的节点，所以要去掉这个节点
        if(index % 2 == 0){
            oNode.next = null;
        }
        jNode.next = pre.next;
        return resNode;
    }

    //打印链表
    private static void printNode(Node headNode){
        StringBuilder builder = new StringBuilder();
        while (headNode.next != null){
            builder.append(headNode.data);
            builder.append("->");
            headNode = headNode.next;
        }
        builder.append(headNode.data);
        System.out.println(builder.toString());
    }
}
