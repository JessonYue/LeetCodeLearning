package com.slow.lib.practice.linkedList;

/**
 * @Author wuchao
 * @Date 2020/7/27-10:49 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class SortLinkedList {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    //时间复杂度O(nlogn)很容易就联想到二分法，找链表的中点，然后断开，递归重复这个步骤，注意两个子链表需要断开，防止出现死循环，直到不能再分割为止
    //即只有一个节点，然后到合并的步骤，new一个dummy节点，将两个子链表的元素从小到大串起来，然后返回这个新链表的头节点，这样一级一级的合并，整个链表就排好序了
    //复杂度分析，因为是二分法，类似归并排序，所以时间复杂度为O(nlogn)，但是因为是递归，空间复杂度为logn
    //所以引入第二个方法用迭代代替递归，将链表分为若干个块，直接从包含一个元素的最小块开始合并，例如node1 和 *2即为4，然后就是node1-node4、node5-node8....依次类推
    //new 一个temp节点，用来串联从小到大的节点，当一个子块都排序好串起来了，则将子块的next指针指向下一块的头部，重复上述步骤。需要先求链表长度，然后子块的大小以1、2、4、8这样递增，i是子块的长度，也就是左右子块长度的边界。
    class Solution {
        public ListNode sortList(ListNode head) {
            // if(head==null){
            //     return head;
            // }
            // ListNode slow = head;
            // ListNode fast = head.next;
            // while(fast!=null&&fast.next!=null){
            //     slow = slow.next;
            //     fast = fast.next.next;
            // }
            // if(slow.next==null){
            //     return slow;
            // }
            // ListNode rightHead = slow.next;
            // slow.next = null;
            // ListNode leftHead = sortList(head);
            // rightHead = sortList(rightHead);
            // ListNode dummy = new ListNode(-1);
            // ListNode newHead = dummy;
            // while(leftHead!=null&&rightHead!=null){
            //     if(leftHead.val<rightHead.val){
            //         newHead.next = leftHead;
            //         leftHead = leftHead.next;
            //     } else {
            //         newHead.next = rightHead;
            //         rightHead = rightHead.next;
            //     }
            //     newHead = newHead.next;
            // }
            // if(leftHead!=null){
            //     newHead.next = leftHead;
            // }
            // if(rightHead!=null){
            //     newHead.next = rightHead;
            // }
            // return dummy.next;
            ListNode dummy = new ListNode(-1);
            dummy.next = head;
            ListNode temp = dummy;
            int length = 0;
            while (temp.next != null) {
                temp = temp.next;
                length++;
            }
            for (int i = 1; i < length; i = i << 1) {
                temp = dummy;
                for (int j = 0; j < length - i; j = j + (i << 1)) {
                    ListNode leftHead = temp.next;
                    ListNode rightHead = leftHead;
                    int leftEnd = 0, rightEnd = 0;
                    while (rightEnd < i) {
                        rightHead = rightHead.next;
                        rightEnd++;
                    }
                    rightEnd = 0;
                    while (leftEnd < i && rightEnd < i && rightHead != null) {
                        if (leftHead.val < rightHead.val) {
                            temp.next = leftHead;
                            leftHead = leftHead.next;
                            leftEnd++;
                        } else {
                            temp.next = rightHead;
                            rightHead = rightHead.next;
                            rightEnd++;
                        }
                        temp = temp.next;
                    }
                    while (leftEnd < i) {
                        temp.next = leftHead;
                        leftHead = leftHead.next;
                        temp = temp.next;
                        leftEnd++;
                    }
                    while (rightEnd < i && rightHead != null) {
                        temp.next = rightHead;
                        rightHead = rightHead.next;
                        temp = temp.next;
                        rightEnd++;
                    }
                    //将子块的next指针指向下一块的头部
                    temp.next = rightHead;
                }
            }
            return dummy.next;
        }
    }
}
