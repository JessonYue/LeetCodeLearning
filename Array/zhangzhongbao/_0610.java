package com.company;

/**
 * 解题思路：
 * 双重遍历法：先获取长度，然后再次遍历的时候将length-n个元素去掉即可
 * 单词遍历法：
 * 1、新增虚拟节点指向头（防止n=1时第一个元素删不掉，同样可以防止找不到当前链表的头）
 * 2、设置prev和next两指针都指向虚拟节点
 * 3、先移动next，让next和prev相距n的长度
 * 4、同时移动prev和next，知道next.next为空
 */
public class _0610 {
    public static void main(String args[]){
        ListNode a1 = new ListNode(1);
        ListNode a2 = new ListNode(2);
        ListNode a3 = new ListNode(3);
        ListNode a4 = new ListNode(4);
        a1.next = a2;
        a2.next = a3;
        a3.next = a4;
        ListNode listNode = removeNthFromEnd(a1, 4);
        printList(listNode);
    }
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode header = new ListNode(-1);
        header.next = head;
        ListNode prev = header;
        ListNode next = header;
        int length = 0;
        for (int i = 0;i<n+1;i++){
            if (next == null){//根本就不超过n，就别移除了
                break;
            }
            next = next.next;
            length++;
        }
        while (next!=null){
            prev = prev.next;
            next = next.next;
            length++;
        }
        if (length>n){
            prev.next = prev.next.next;
        }
        return header.next;
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
