package com.company;

/**
 * 回文链表 1-2-3-2-1
 * 起初未仔细审题的时候以为只要扔到一个数组里面直接对比就完事儿，后来发现空间不能超过O(n)，将条件限制死了
 * 如果是基本数据类型倒是可以格式化数据为字符串，然后翻转链表再格式化数据为字符串，两相对比就可以解决。
 * 后经过查证，最优答案为快慢指针，
 * 1、快指针是慢指针的2倍，快指针走完的时候，慢指针刚好在链表中间部分的附近。
 * 2、将前面或者后面的链表翻转，一对比就知道答案了
 */
public class _0612 {
    public static void main(String args[]) {
        ListNode a1 = new ListNode(1);
        ListNode a2 = new ListNode(2);
        ListNode a3 = new ListNode(3);
        ListNode a4 = new ListNode(2);
        ListNode a5 = new ListNode(1);
        a1.next = a2;
        a2.next = a3;
        a3.next = a4;
        a4.next = a5;
        boolean isPalindrome = isPalindrome(a1);
        System.out.println("是否是回文："+isPalindrome);

    }

    public static boolean isPalindrome(ListNode head) {
        //虚拟节点
        ListNode dummyNode = new ListNode(-1);
        dummyNode.next = head;
        ListNode fast = dummyNode;
        ListNode slow = dummyNode;
        ListNode pre = null;
        //临时节点
        ListNode temp = null;
        //慢指针走一步，快指针走两步，最终的结果慢指针在中间节点附近
//        while (fast!=null && fast.next.next!=null){
//            //快指针走两步
//            fast = fast.next.next;
//            //慢指针走一步
//            temp = slow.next;
//            slow.next = pre;
//            pre = slow;
//            slow = temp;
//        }
        while (fast !=null && fast.next!=null){
            //快指针走两步
            fast = fast.next.next;
            //翻转前部分链表
            temp = slow.next;
            slow.next = pre;
            //pre永远指向被翻转列表的最前面
            pre = slow;//执行完这句，slow这个变量就可以任意使用了
            slow = temp;
        }
        ListNode middleNode;
        //链表为偶数
        if (fast!=null){
            middleNode = slow.next.next;
        }else{
            middleNode = slow.next;
        }
        while (pre!=null && middleNode!=null){
            if (pre.val!=middleNode.val){
                return false;
            }
            pre = pre.next;
            middleNode = middleNode.next;
        }
        return true;
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
