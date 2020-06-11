package com.company;

/**
 * 归并两个有序链表
 * 解题思路：
 * 1、固定一个header，这个header是用来取最终结果的链表
 * 2、再添加一个next，用来取两个链表中val最小的数据
 * 3、当next确定之后，需要将l1或者l2移到下一位
 * 4、上步操作完成后next的元素已经确定，就可以将next往下移动一位
 */
public class _0609 {
    public static void main(String args[]) {
        ListNode a1 = new ListNode(1);
        ListNode a2 = new ListNode(2);
        ListNode a3 = new ListNode(3);
        ListNode a4 = new ListNode(4);
        a1.next = a2;
        a2.next = a3;
        a3.next = a4;
        ListNode b1 = new ListNode(11);
        ListNode b2 = new ListNode(21);
        ListNode b3 = new ListNode(31);
        ListNode b4 = new ListNode(41);
        b1.next = b2;
        b2.next = b3;
        b3.next = b4;
        ListNode listNode = mergeTwoLists(a1, b1);
        printList(listNode);
    }
    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode next = head;
        int i = 0;
        while (l1!=null && l2!=null){
            if (l1.val<=l2.val){
                next.next = l1;
                l1 = l1.next;
            }else{
                next.next = l2;
                l2 = l2.next;
            }
            System.out.print(++i+":");
            //上面的步骤next的值已经确定了，此时就可以将next指针指向下一位
            next = next.next;
            printList(head);
        }
        //如果l1和l2不是等长的话，总有一个先执行完毕，将未执行完毕的直接合并过来即可
        next.next = l1!=null ?l1:l2;
        return head.next;
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
