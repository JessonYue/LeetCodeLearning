package com.lanfairy.md.queue;

public class deleteNode {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
    public void deleteNode(ListNode node) {
        //node 为要删除的节点  无法找到它的前一个节点
        //就将 node 的后一个节点的值赋值给 node  然后再删除 node 后面的节点 从而达到删除 node结点的目的
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
