package com.example.lsn37_dagger2_subcomponent;

/**
 * 面试题 02.02. 返回倒数第 k 个节点
 */
public class Solution07_01 {

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x){
            this.val = x;
        }
    }

    public int kthToLast(ListNode head,int k){
        if(head == null || k<0){
           return -1;
        }
        ListNode fast = head;
        ListNode low = head;
        while (k!=0){
            fast = fast.next;
            k--;
        }
        while(fast!=null){
            fast = fast.next;
            low = low.next;
        }
        return low.val;
    }

}
