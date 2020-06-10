

//

public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode prehead = new ListNode(-1);//首先声明一个空节点

        ListNode prev = prehead;
        while (l1 != null && l2 != null) {//遍历  前提是有序的，最后将一方剩余的直接接入即可
        if (l1.val <= l2.val) {
           prev.next = l1;
           l1 = l1.next;
        } else {
           prev.next = l2;
           l2 = l2.next;
        }
            prev = prev.next;
        }

        //最后将头部head返回
        prev.next = l1 == null ? l2 : l1;

        return prehead.next;
}

