package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        NodeList nodeList1 = new NodeList();
        nodeList1.add(new Node(1));
        nodeList1.add(new Node(3));
        nodeList1.add(new Node(5));

        NodeList nodeList2 = new NodeList();
        nodeList2.add(new Node(1));
        nodeList2.add(new Node(6));
        nodeList2.add(new Node(8));

        Node headNode1 = nodeList1.head;
        printNode(headNode1);

        Node headNode2 = nodeList2.head;
        printNode(headNode2);

        Node node = mergeList(headNode1, headNode2);
        printNode(node);
    }

    //合并链表
    private static Node mergeList(Node l1, Node l2){
        Node mergedNode = new Node(-1);
        Node pre = mergedNode;
        if(l1 == null){
            return l2;
        }

        if(l2 == null){
            return l1;
        }

        if(l1 == null && l2 == null){
            return null;
        }

        //初始化时头节点设置的为0，所以这里指向头节点下一个节点
        l1 = l1.next;
        l2 = l2.next;
        while (l1 != null && l2 != null){
            if(l1.data <= l2.data){
                pre.next = l1;
                l1 = l1.next;
            } else {
                pre.next = l2;
                l2 = l2.next;
            }
            pre = pre.next;
        }
        pre.next = l1 == null ? l2 : l1;

        return mergedNode.next;
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
