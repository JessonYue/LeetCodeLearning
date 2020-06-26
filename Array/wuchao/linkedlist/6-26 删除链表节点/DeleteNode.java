package com.slow.lib.practice.linkedList;

/**
 * 因为只给定了要删除的节点，没有给定前置节点，所以只知道这个节点之后的节点信息
 * 可以将下一个节点的值拷贝到这个节点，将下一个节点作为真正删除的节点
 * @Author wuchao
 * @Date 2020/6/26-9:00 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class DeleteNode {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public void deleteNode(ListNode node) {
        ListNode next = node.next;
        node.val = next.val;
        node.next = next.next;
        next.next = null;
        next = null;
    }
}
