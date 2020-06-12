package com.chow;

public class Main {

    public static void main(String[] args){
        NodeList nodeList = new NodeList();
        nodeList.add(new Node(1));
        nodeList.add(new Node(2));
        nodeList.add(new Node(3));
        nodeList.add(new Node(4));
        nodeList.add(new Node(5));
        nodeList.add(new Node(3));
        nodeList.add(new Node(2));
        nodeList.add(new Node(1));

        Node headNode = nodeList.head;
        printNode(headNode);

        boolean isPalind = isPalindrome(headNode.next);
        System.out.println(isPalind);
    }

    //判断是否是回文链表
    private static boolean isPalindrome(Node headNode){
        Node firstNode = headNode;
        Node secondNode = headNode;

        while (firstNode.next.next != null && secondNode.next != null){
            firstNode = firstNode.next.next;
            secondNode = secondNode.next;
        }
        secondNode = reverseList(secondNode.next);
        while (secondNode != null){
            if(secondNode.data != headNode.data){
                return false;
            }
            secondNode = secondNode.next;
            headNode = headNode.next;
        }

        return true;
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
