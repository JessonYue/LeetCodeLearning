package com.example.lsn37_dagger2_subcomponent;

public class Solution06_30 {

    class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            this.val = x;
            this.next = null;
        }
    }

    public ListNode reverseList(ListNode head){
        if(head == null){
            return head;
        }
        ListNode newHead = null;
        ListNode next = head;
        ListNode temp = null;
        while(next != null){
            temp = next.next;
            next.next = newHead;
            newHead = next;
            next = temp;
        }
        return newHead;
    }

}
