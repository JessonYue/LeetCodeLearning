package com.lanfairy.md;

public class MergeTwoSortedLists {
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

    public static void main(String[] args) {

    }


    public ListNode mergeTwoLists1(ListNode l1, ListNode l2) {
        if(l1==null || l2== null)return l1==null ? l2 : l1;
        ListNode mergeList = null;
        ListNode l1Cur = l1;
        ListNode l2Cur = l2;
        ListNode current = null;
        if (l1Cur.val<l2Cur.val){
            current =  new ListNode(l1Cur.val);

            l1Cur = l1Cur.next;
        }else {
            current = new ListNode(l2Cur.val);
            l2Cur = l2Cur.next;
        }
         mergeList = current;
        while (l1Cur!=null && l2Cur!=null){
            ListNode next = null;
            if (l1Cur.val<l2Cur.val){
                next=  new ListNode(l1Cur.val);
                l1Cur = l1Cur.next;
            }else {
                next = new ListNode(l2Cur.val);
                l2Cur = l2Cur.next;
            }
            current.next = next;
            current = next;
        }

        while (l1Cur!=null){
            ListNode next = new ListNode(l1Cur.val);
            current.next = next;
            current = next;
            l1Cur = l1Cur.next;
        }
        while (l2Cur!=null){
            ListNode next = new ListNode(l2Cur.val);
            current.next = next;
            current = next;
            l2Cur = l2Cur.next;
        }


        return mergeList;
    }

    public ListNode mergeTwoLists2(ListNode l1, ListNode l2) {
       ListNode current = new ListNode(-1);
        ListNode pre = current;
       while (l1!=null && l2!=null){
           if (l1.val < l2.val){
               current.next = l1;
               l1 = l1.next;
           }else {
               current.next = l2;
               l2 = l2.next;
           }
           current = current.next;
       }
        current.next = l1!=null ? l1 : l2;

        return pre.next;
    }

    /**采用递归***/

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
       if (l1==null)
           return l2;
       if (l2==null)
           return l1;
       if (l1.val < l2.val){
           l1.next = mergeTwoLists(l1.next, l2);
           return l1;
       }else {
           l2.next = mergeTwoLists(l1, l2.next);
           return l2;
       }
    }
}
