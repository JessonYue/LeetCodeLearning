    class Solution {
        public ListNode removeNthFromEnd(ListNode head, int n) {
            ListNode p,q;
            p=q=head;

            while(p!=null){
               if(n<0){
                   q = q.next;
               }
               n--;
               p = p.next;
            }
            if(n==0){
                return head.next;
            }
            q.next = q.next.next;
            return head;


        }
    }