public class Solution_06_12 {

    /**
     * 整体思路
     * 1，通过快慢指针或者后半部分的链表
     * 2，反转后半部分链表
     * 3，反转后的后半部分链表和前半部分链表比较
     *
     */
    public boolean isPalindrome(ListNode head) {
        if(head==null||head.next==null)return true;
        if(head.next.next==null)return head.val==head.next.val;
        ListNode pre=head;
        ListNode pos=head;

        while(pos!=null&&pos.next!=null){
            pre=pre.next;
            pos=pos.next.next;
        }

        ListNode revPre=reverse(pre);//链表反转
        ListNode pos1=head;
        while(revPre!=null){
            if(revPre.val!=pos1.val)return false;
            revPre=revPre.next;
            pos1=pos1.next;
        }
        return true;
    }

    ListNode reverse(ListNode node){

        ListNode revNode=null;
        if(node.next==null)return node;
        while(node!=null){
            ListNode temp=new ListNode(node.val);
            temp.next=revNode;
            revNode=temp;
            node=node.next;
        }

        return revNode;
    }
    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
}
