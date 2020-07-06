package day09;





public class day09 {

    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    class Solution {
        //暴力 迭代
        //思路:定义一个哑结点 初始值为null,比较l1,l2,如果小于等于,添加到新的链表
        //临界:其中一方l1,l2为null,跳出
        //情况:如果一方为null,直接将新节点指向将不为null的部分
        public ListNode mergeTwoLists1(ListNode l1, ListNode l2) {
            ListNode dump = new ListNode(-1);
            ListNode dumphelper = dump;

            while (l1 != null && l2 != null){
                if(l1.val <= l2.val){
                    dumphelper.next = l1;
                    l1 = l1.next;
                    dumphelper = dumphelper.next;
                }else{
                    dumphelper.next = l2;
                    l2 = l2.next;
                    dumphelper = dumphelper.next;
                }
            }
            if(l1 == null)
                dumphelper.next = l2;
            if(l2 == null)
                dumphelper.next = l1;
            return dump.next;
        }

        //思路:递归 定义f(l1,l2)
        //1.其中一方l1,l2为null,直接跳出
        //临界,l1,l2为null
        public ListNode mergeTwoLists2(ListNode l1, ListNode l2) {

            if(l1 == null)
                return l2;
            if(l2 == null)
                return l1;

            if(l1.val <= l2.val){
                l1.next = mergeTwoLists2(l1.next,l2);
                return l1;
            }else{
                l2.next = mergeTwoLists2(l1,l2.next);
                return l2;
            }
        }
    }

}




