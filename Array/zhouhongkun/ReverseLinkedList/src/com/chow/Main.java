package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here

        NodeList nodeList = new NodeList();
        nodeList.add(new Node(1));
        nodeList.add(new Node(3));
        nodeList.add(new Node(5));
        nodeList.add(new Node(7));
        nodeList.add(new Node(9));

        Node headNode = nodeList.head;
        printNode(headNode);

        //反转链表
        Node reverseHead = reverseList(nodeList.head);
        printNode(reverseHead);

    }

    //反转链表
    private static Node reverseList(Node head){
        Node pre = null;
        Node cur = head;
        Node tmp;
        while (cur != null){
            tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
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
