package com.example.lsn37_dagger2_subcomponent;

public class Solution06_26 {

    static class ListNode{
        int val;
        ListNode next;

        ListNode(int x){
            val = x;
            next = null;
        }
    }

    class Solution{
        public void deleteNode(ListNode node){
            node.val = node.next.val;
            node.next = node.next.next;
        }
    }

}
