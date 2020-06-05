package com.chow;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        Node node8= new Node(8);
        Node node4= new Node(4);
        Node node5= new Node(5);

        MyNodeList listA = new MyNodeList();
        listA.add(new Node(4));
        listA.add(new Node(1));
        listA.add(node8);
        listA.add(node4);
        listA.add(node5);

        MyNodeList listB = new MyNodeList();
        listB.add(new Node(5));
        listB.add(new Node(0));
        listB.add(new Node(1));
        listB.add(node8);

        Node node = getCrossNode(listA.head, listB.head);

        System.out.println(node);
    }

    /**
     * 分别循环遍历两个list，当下一个节点为null时，就指向另一个list的头节点，这样如果有相交点的话，就一点能碰上
     * @param headA
     * @param headB
     * @return
     */
    private static Node getCrossNode(Node headA, Node headB) {

        if(headA == null || headB == null) {
            return null;
        }

        Node a = headA;
        Node b = headB;
        while(a != b){
            if(a == null){
                a = headB;
            } else {
                a = a.next;
            }

            if(b == null){
                b = headA;
            } else {
                b = b.next;
            }
        }
        return a;
    }
}
