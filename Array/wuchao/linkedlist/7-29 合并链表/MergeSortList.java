package com.slow.lib.practice.linkedList;

/**
 * 一个迭代实现，一个递归实现
 * @Author wuchao
 * @Date 2020/7/29-9:13 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class MergeSortList {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // if(l1==null){
        //     return l2;
        // }
        // if(l2==null){
        //     return l1;
        // }
        // ListNode next1 = l1;
        // ListNode next2 = l2;
        // ListNode mergedList = new ListNode();
        // ListNode temp = mergedList;
        // while(next1!=null&&next2!=null){
        //     if(next1.val<next2.val){
        //         temp.next = next1;
        //         next1 = next1.next;
        //     } else {
        //         temp.next = next2;
        //         next2 = next2.next;
        //     }
        //     temp = temp.next;
        // }

        // if(next2!=null){
        //     temp.next = next2;
        // }
        // if(next1!=null) {
        //     temp.next = next1;
        // }
        // return mergedList.next;
        ListNode dummy = new ListNode(-1);
        merge(dummy, l1, l2);
        return dummy.next;

    }

    public void merge(ListNode root, ListNode left, ListNode right) {
        if (left == null && right == null) {
            return;
        }
        if (left == null) {
            root.next = right;
            merge(root.next, left, right.next);
            return;
        }
        if (right == null) {
            root.next = left;
            merge(root.next, left.next, right);
            return;
        }

        if (left.val < right.val) {
            root.next = left;
            merge(root.next, left.next, right);
            return;
        } else {
            root.next = right;
            merge(root.next, left, right.next);
            return;
        }
    }
}
