public class Solution_06_29 {


public int kthToLast(ListNode head, int k) {
        ListNode p = head;
        for(int i=0;i<k;i++){
          p = p.next;  
        }

        while(p != null){
            p = p.next;
            head = head.next;
        }

        return head.val;
    }


}
