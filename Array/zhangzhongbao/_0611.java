package com.company;

/**
 * 链表按照奇偶元素聚集，要求算法空间复杂度为O(1)
 * 数据特点是：奇元素与偶元素相邻，不允许开辟消耗大量内存的数据结构
 * 解题思路：
 * 1、需要有两个变量来控制奇、偶表头，方便查找，还需要两个移动变量控制移动，元素还是使用之前链表的元素
 * 2、奇元素.next指向下一个偶元素，偶元素.next指向下一个奇元素
 * 3、当设置完奇元素和偶元素的时候，需要分别将它们的移动变量移动到下一个
 */
public class _0611 {
    public static void main(String args[]) {
        ListNode a1 = new ListNode(1);
        ListNode a2 = new ListNode(2);
        ListNode a3 = new ListNode(3);
        ListNode a4 = new ListNode(4);
        a1.next = a2;
        a2.next = a3;
        a3.next = a4;
        ListNode listNode = oddEvenList(a1);
        printList(listNode);
    }

    public static ListNode oddEvenList(ListNode head) {
        if (head == null) return null;
        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenHead = even;

        while (even != null && even.next != null) {
            //这块最重要的理解是.next一直和后面剩余部分链表关联着，odd和even只相差一个元素
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        //遍历到终点将偶节点添加到基节点的后面
        odd.next = evenHead;
        return head;
    }

    private static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + " ");
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
