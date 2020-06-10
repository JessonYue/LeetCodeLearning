package com.company;

/**
 * 反转链表
 * 解题思路1：使用迭代
 * 1、保留一份next元素的的引用，保留一份pre元素的引用
 * 2、遍历的时候将pre赋值给当前元素的next，然后将pre移动到当前元素的位置
 * 解题思路2：使用递归
 * 1、递归有个特点就是出口位置才能确定计算的值、数据、方向等
 * 2、由于链表不知长度，不知最后元素，但是肯定知道最后元素的next元素一定为null，以此作为出口，从后向前一段一段的进行翻转
 */
public class _0608 {
    public static void main(String args[]) {
        //node A
        ListNode a1 = new ListNode(1);
        ListNode a2 = new ListNode(2);
        ListNode a3 = new ListNode(3);
        ListNode a4 = new ListNode(4);
        ListNode a5 = new ListNode(5);
        a1.next = a2;
        a2.next = a3;
        a3.next = a4;
        a4.next = a5;
        a5.next = null;
        printList(a1);
//        ListNode reverseList = reverseList(a1);
        ListNode reverseList = recusionList(a1);
        printList(reverseList);


    }

    /**
     * 迭代法：翻转链表
     * @param head
     * @return
     */
    public static ListNode reverseList(ListNode head) {
        ListNode node = head;
        ListNode preNode = null;
        while (node!=null){
            ListNode nextNode = node.next;
            node.next = preNode;
            preNode = node;
            node = nextNode;
        }
        return preNode;
    }

    /**
     * 递归法翻转数组
     * @param header
     */
    public static ListNode recusionList(ListNode header){
        if (header == null || header.next == null){
            return header;
        }
        ListNode temp = recusionList(header.next);
        header.next.next = header;
        header.next = null;
        return temp;
    }

    private static void printList(ListNode node){
        while (node!=null){
            System.out.print(node.val+" ");
            node = node.next;
        }
        System.out.println();
    }
    private static class ListNode {
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
