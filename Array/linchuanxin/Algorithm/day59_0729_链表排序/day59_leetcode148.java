package day59_0729;




public class day58_leetcode148 {

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode sortList(ListNode head) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        //统计长度
        ListNode p = dummyHead.next;
        int length = 0;
        while (p!=null){
            ++length;
            p = p.next;
        }
        //循环切割合并
//        for (int size = 1; size < length; size++) {
        for (int size = 1; size < length; size<<=1) {
            ListNode cur = dummyHead.next;
            ListNode tail = dummyHead;
            while (cur!=null){
                ListNode left = cur;
                ListNode right = cut(cur,size);
                cur = cut(right,size);
                tail.next = merge(left,right);
                while (tail.next != null)
                    tail = tail.next;
            }
        }
        return dummyHead.next;
    }

    /**
     * 合并list1和list2
     * @param list1
     * @param list2
     * @return
     */
    public static ListNode merge(ListNode list1, ListNode list2){
//        ListNode dummyHead = new ListNode(Integer.MIN_VALUE), p = dummyHead;
        ListNode dummyHead = new ListNode(-1), p = dummyHead;
        while (list1!=null && list2!=null){
            if(list1.val< list2.val){
                p.next = list1;
                list1 = list1.next;
            }else{
                p.next = list2;
                list2 = list2.next;
            }
            p = p.next;
        }
        if(list1==null)
            p.next = list2;
        else
            p.next = list1;
        return dummyHead.next;
    }

    /**
     * 将链表L切掉前n个节点 并返回后半部分的链表头
     * @param head
     * @param n
     * @return
     */
    public static ListNode cut(ListNode head, int n){
        if(n <= 0)
            return head;
        ListNode p = head;
        // 往前走n-1步
        while (--n > 0 && p != null)
            p = p.next;
        if (p == null)
            return null;
        ListNode next = p.next;
        p.next = null;
        return next;
    }
}
