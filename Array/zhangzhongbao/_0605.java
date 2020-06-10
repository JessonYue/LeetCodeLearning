package com.company;

/**
 * 两链表相交
 * 解题思路：ListA+ListB = ListB+ListA，如果超出AB长度就会出现下一节点都为null的情况
 * 因为是链表，没法知道长度，所以可以使用循环AB来判断相交点
 * 如果是普通的array，直接使用倒序比较的方式就ok，比链表操作的还要快
 */
public class _0605 {
    public static void main(String args[]) {
        //node A
        ListNode a1 = new ListNode(1);
        ListNode a2 = new ListNode(2);
        ListNode a3 = new ListNode(3);
        ListNode a4 = new ListNode(4);
        a1.next = a2;
        a2.next = a3;
        a3.next = a4;
        a4.next = null;
        //node B
        ListNode b1 = new ListNode(41);
        ListNode b2 = new ListNode(42);

        b1.next = b2;
        //测试相交
        b2.next = a3;
        a3.next = a4;
        a4.next = null;
        ListNode intersectionNode = getIntersectionNode(a1,b1);
        if (intersectionNode!=null){
            System.out.println(intersectionNode);
        }

        //测试没有交集
        ListNode b3 = new ListNode(3);
        ListNode b4 = new ListNode(4);
        ListNode b5 = new ListNode(5);
        b2.next = b3;
        b3.next = b4;
        b4.next = b5;
        b5.next = null;
        intersectionNode = getIntersectionNode(a1,b1);
        if (intersectionNode !=null){
            System.out.println(intersectionNode);
        }else{
            System.out.println("暂时没有相交的数据");
        }


    }
    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode nodeA = headA;
        ListNode nodeB = headB;
        int i=0;
        //当node A+node B都执行了 A+B的长度后，如果没有相交部分，最后next节点一定相等
        while (nodeA!=nodeB){
            if (nodeA == null){
                nodeA = headB;
            }else{
                nodeA = nodeA.next;
            }
            if (nodeB == null){
                nodeB = headA;
            }else {
                nodeB = nodeB.next;
            }
            System.out.println("循环了："+(++i)+"圈");
        }
        return nodeA;
    }

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }

        @Override
        public String toString() {
            return "ListNode{" +
                    "val=" + val +
                    ", next=" + next +
                    '}';
        }
    }
}
