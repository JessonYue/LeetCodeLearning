package day60_0730;




public class day60_leetcode21 {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }


    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dump = new ListNode(-1);
        ListNode dumphelper = dump;
        while(l1!=null && l2!=null){
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

}
