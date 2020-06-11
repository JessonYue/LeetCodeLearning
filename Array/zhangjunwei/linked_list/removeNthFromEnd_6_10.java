package com.lanfairy.md;

import java.util.Queue;

public class removeNthFromEnd_6_10 {
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }




    //看过题解后  用快慢指针来解决问题
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //哑节点  方便处理删除 head节点的 情况
        ListNode dumpNode = new ListNode(0);
        dumpNode.next = head;
        ListNode p = dumpNode;//快指针
        ListNode q = dumpNode;//慢指针
        //从第一个节点开始  快指针先走 n步
        for (int i = 1; i <= n + 1; i++) {
            p = p.next;
        }
        //快慢指针一起走
        while (p != null) {
            p = p.next;
            q = q.next;
        }
        //找到了要删除的结点 就是q后面哪个结点
        q.next = q.next.next;

        return dumpNode.next;
    }
}
