public class Solution_06_09 {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null)return l2;
        if(l2==null)return l1;
        ListNode pre=new ListNode(-1);
        ListNode head=pre;
        while(l1!=null&&l2!=null){
            if(l1.val<=l2.val){
                pre.next=l1;
                l1=l1.next;
            }else{
                pre.next=l2;
                l2=l2.next;
            }
            pre=pre.next;
        }
        if(l1!=null)pre.next=l1;
        if(l2!=null)pre.next=l2;
        return head.next;
    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
}
